#include "CHttpUrl.hpp"

// CLASS CONSTANTS ============================================================

const char* PROTOCOL_DELIM = "://";
const char* DOCUMENT_DELIM = "/";
const char* PORT_DELIM = ":";
const char* DEFAULT_PROTOCOL = "http";

const int MINIMAL_DOMAIN_LENGTH = 1;

std::set<char> END_OF_LINE_SYMBOLS = { '\0', '\n', '\r' };
std::set<char> UNRESERVED_SYMBOLS = { '-', '.', '_', '~' };

// ============================================================================

// Выполняет парсинг строкового представления URL-а, в случае ошибки парсинга
// выбрасыват исключение CUrlParsingError, содержащее текстовое описание ошибки
CHttpUrl::CHttpUrl(std::string const& url)
{
	ParseUrl(url);
}

// Инициализируют URL на основе переданных параметров.
// При недопустимости входных параметров выбрасывают исключение std::invalid_argument
// Если имя документа не начинается с символа /, то добавляют / к имени документа.
CHttpUrl::CHttpUrl(std::string const& domain, std::string const& document, Protocol protocol)
{
	SetProtocol(protocol);
	SetDomain(domain);
	SetDocument(document);
}

CHttpUrl::CHttpUrl(std::string const& domain, std::string const& document, Protocol protocol, unsigned short port)
{
	SetProtocol(protocol);
	SetDomain(domain);
	SetPort(port);
	SetDocument(document);
}

// GETTERS ====================================================================

// Возвращает строковое представление URL-а.
// Порт, являющийся стандартным для выбранного протокола (80 для http и 443 для https) в URL не должен включаться
std::string CHttpUrl::GetURL() const
{
	std::string port;
	if (m_port != PROTOCOL_DESCRIPTION[m_protocol].defaultPort)
	{
		port = ":" + std::to_string(m_port);
	}
	return PROTOCOL_DESCRIPTION[m_protocol].protToStr + "://" + m_domain + port + m_document;
}

// Возвращает доменное имя
std::string CHttpUrl::GetDomain() const
{
	return m_domain;
}

// Возвращает имя документа.
// Примеры: / , /index.html , /images/photo.jpg
std::string CHttpUrl::GetDocument() const
{
	return m_document;
}

// Возвращает тип протокола
Protocol CHttpUrl::GetProtocol() const
{
	return m_protocol;
}

// Возвращает номер порта
unsigned short CHttpUrl::GetPort() const
{
	return m_port;
}

// PARSING =====================================================================

// [protocol//:]domain[:port]/document
void CHttpUrl::ParseUrl(const std::string& url)
{
	try
	{
		std::string protocolStr(DEFAULT_PROTOCOL);
		size_t domainPos = 0;
		size_t protocolPos = url.find(PROTOCOL_DELIM);
		if (protocolPos != std::string::npos)
		{
			protocolStr = url.substr(0, protocolPos);
			domainPos = protocolPos + std::strlen(PROTOCOL_DELIM);
		}
		Protocol protocol = StringToProtocol(protocolStr); // std::invalid_argument possible
		std::string domainStr = url.substr(domainPos); // std::out_of_range possible
		std::string documentStr;
		size_t documentPos = domainStr.find(DOCUMENT_DELIM);
		if (documentPos != std::string::npos)
		{
			documentStr = domainStr.substr(documentPos);
			domainStr = domainStr.substr(0, documentPos);
		}
		std::string portStr;
		unsigned short port = PROTOCOL_DESCRIPTION[protocol].defaultPort;
		size_t portPos = domainStr.find(PORT_DELIM);
		if (portPos != std::string::npos)
		{
			portStr = domainStr.substr(portPos + 1); // std::out_of_range possible
			domainStr = domainStr.substr(0, portPos);
			port = StringToPort(portStr); // std::invalid_argument possible
		}
		SetProtocol(protocol); // std::invalid_argument possible
		SetDomain(domainStr);
		SetPort(port);
		SetDocument(documentStr);
	}
	catch (...)
	{
		throw CUrlParsingError("Error: bad url format.");
	}
}

// https://tools.ietf.org/html/rfc1738
// URL schemeparts for ip based protocols:
// ip-schemepart  = "//" login [ "/" urlpath ]
// login          = [ user [ ":" password ] "@" ] hostport
// HOSTPORT       = HOST [ ":" PORT ]
// HOST           = HOSTNAME | HOSTNUMBER
// HOSTNAME       = *[ DOMAINLABEL "." ] TOPLABEL
// DOMAINLABEL    = ALPHADIGIT | ALPHADIGIT *[ ALPHADIGIT | "-" ] ALPHADIGIT
// TOPLABEL       = ALPHA | ALPHA *[ ALPHADIGIT | "-" ] ALPHADIGIT
// ALPHADIGIT     = ALPHA | DIGIT
// HOSTNUMBER     = DIGITS "." DIGITS "." DIGITS "." DIGITS
// PORT           = DIGITS
// user           = *[ uchar | ";" | "?" | "&" | "=" ]
// password       = *[ uchar | ";" | "?" | "&" | "=" ]
// urlpath        = *xchar    ; depends on protocol see section 3.1

// set domain with checking to correct
void CHttpUrl::SetDomain(const std::string& domain)
{
	// parse domain to parts
	std::vector<std::string> partsCont = ParseString(domain, '.');
	if (partsCont.size() < MINIMAL_DOMAIN_LENGTH)
	{
		throw std::invalid_argument("Error: bad domain length.");
	}
	// check parts to correct
	for (std::string& part : partsCont)
	{
		if (part.empty())
		{
			throw std::invalid_argument("Error: bad domain name.");
		}
		bool discardDelim = true;
		char symbol;
		for (size_t i = 0; i < part.size(); i++)
		{
			symbol = part[i];
			if (symbol == '-')
			{
				if (discardDelim || i == 0 || i == part.size() - 1)
				{
					throw std::invalid_argument("Error: bad domain name.");
				}
			}
			else
			{
				if (!std::isalnum(static_cast<unsigned char>(symbol)))
				{
					throw std::invalid_argument("Error: bad domain name.");
				}
				discardDelim = false;
			}
		}
	}
	m_domain = domain;
}

// https://tools.ietf.org/html/rfc3986#section-3.3
// path =
// path-abempty ; begins with "/" or is empty
// / path-absolute ; begins with "/" but not "//"
// / path-noscheme ; begins with a non-colon segment
// / path-rootless ; begins with a segment
// / path-empty    ; zero characters
// PATH-ABEMPTY  = *( "/" SEGMENT )
// path-absolute = "/" [ segment-nz *( "/" segment ) ]
// path-noscheme = segment-nz-nc *( "/" segment )
// path-rootless = segment-nz *( "/" segment )
// path-empty    = 0<pchar>
// SEGMENT       = *PCHAR
// segment-nz    = 1*pchar
// segment-nz-nc = 1*( unreserved / pct-encoded / sub-delims / "@" ) ; non-zero-length segment without any colon ":"
// PCHAR       = UNRESERVED / pct-encoded / sub-delims / ":" / "@"
// UNRESERVED  = ALPHA / DIGIT / "-" / "." / "_" / "~"
// reserved    = gen-delims / sub-delims
// gen-delims  = ":" / "/" / "?" / "#" / "[" / "]" / "@"
// sub-delims  = "!" / "$" / "&" / "'" / "(" / ")" / "*" / "+" / "," / ";" / "="

// set document with checking to correct
void CHttpUrl::SetDocument(const std::string& document)
{
	std::string path;
	if (document == "/" || document.empty())
	{
		path = "/";
	}
	else
	{
		// parse document to parts
		std::vector<std::string> partsCont = ParseString(document, '/');
		// check parts to correct
		for (size_t i = 0; i < partsCont.size(); i++)
		{
			std::string part = partsCont[i];
			if (!part.empty())
			{
				for (size_t j = 0; j < part.size(); j++)
				{
					char symbol = part[j];
					if (UNRESERVED_SYMBOLS.count(symbol) == 0)
					{
						if (!std::isalnum(static_cast<unsigned char>(symbol)))
						{
							throw std::invalid_argument("Error: bad domain name.");
						}
					}
				}
				path += "/" + part; // add part to path
			}
			else if (i != 0)
			{
				throw std::invalid_argument("Error: bad domain name.");
			}
		}
	}
	m_document = path;
}

// set protocol with checking to correct
void CHttpUrl::SetProtocol(Protocol protocol)
{
	if (PROTOCOL_DESCRIPTION.count(protocol) == 0)
	{
		throw std::invalid_argument("Error: Unexpected protocol.");
	}
	m_protocol = protocol;
	SetPort(PROTOCOL_DESCRIPTION[protocol].defaultPort);
}

// set port with checking to correct
void CHttpUrl::SetPort(unsigned short port)
{
	m_port = port;
}

// ============================================================================

// convert string to protocol
Protocol CHttpUrl::StringToProtocol(const std::string& string) const
{
	bool err = true;
	Protocol protocol;
	std::string protStr;
	for (auto const& protPair : PROTOCOL_DESCRIPTION)
	{
		protStr = protPair.second.protToStr; // string's value
		if (protStr == string)
		{
			protocol = protPair.first;
			err = false;
			break;
		}
	}
	if (err)
	{
		throw std::invalid_argument("Error: convertion string to protocol was failed.");
	}
	return protocol;
}

// convert string to port
unsigned short CHttpUrl::StringToPort(const std::string& string) const
{
	int num = 0;
	try
	{
		size_t pos;
		num = std::stoi(string, &pos, 10);
		if (pos != string.size() || num < 0 || num > USINT_MAX)
		{
			throw std::exception();
		}
	}
	catch (...)
	{
		throw std::invalid_argument("Error: convertion string to port was failed.");
	}
	return (unsigned short)num;
}

// parse string to substrings
std::vector<std::string> CHttpUrl::ParseString(const std::string& string, char delim) const
{
	std::vector<std::string> subStringContainer;
	std::string subString;
	char symbol;
	for (size_t i = 0; i < string.size(); i++)
	{
		symbol = string[i];
		if (symbol == delim)
		{
			subStringContainer.push_back(subString);
			subString.clear();
		}
		else if (END_OF_LINE_SYMBOLS.count(symbol) == 0)
		{
			subString.push_back(symbol);
		}
		else
			break;
	}
	if (symbol == delim || !subString.empty())
	{
		subStringContainer.push_back(subString);
	}
	return subStringContainer;
}
