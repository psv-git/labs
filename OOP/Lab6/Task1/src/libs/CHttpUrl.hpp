#ifndef CHTTPURL_HPP
#define CHTTPURL_HPP

#include "../task/stdafx.h"
#include "CUrlParsingError.hpp"
#include "Global.hpp"

class CHttpUrl
{
public:
	CHttpUrl(std::string const& url);
	CHttpUrl(std::string const& domain, std::string const& document, Protocol protocol = Protocol::HTTP);
	CHttpUrl(std::string const& domain, std::string const& document, Protocol protocol, unsigned short port);

	std::string GetURL() const;
	std::string GetDomain() const;
	std::string GetDocument() const;
	Protocol GetProtocol() const;
	unsigned short GetPort() const;

private:
	Protocol m_protocol;
	std::string m_domain;
	std::string m_document;
	unsigned short m_port;

	void ParseUrl(const std::string& domain);
	void SetProtocol(Protocol protocol);
	void SetDomain(const std::string& domain);
	void SetPort(unsigned short port);
	void SetDocument(const std::string& document);

	Protocol StringToProtocol(const std::string& string) const;
	unsigned short StringToPort(const std::string& string) const;
	std::vector<std::string> ParseString(const std::string& str, char delim) const;
};

#endif // CHTTPURL_HPP
