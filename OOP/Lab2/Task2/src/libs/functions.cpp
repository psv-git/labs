#include "functions.hpp"

// print program info
void PrintProgramInfo()
{
	std::wcout << std::endl
			   << L"Программа, выполняет построчное html-кодирование текста, поступающего со стандартного потока ввода, и выводит результат в стандартный поток вывода." << std::endl
			   << std::endl;
}

// print program exit status
void PrintExitInfo(int exitCode)
{
	switch (exitCode)
	{
	case 0:
		break;
	case 1:
		std::wcout << L"Error code " << exitCode << L": undefined argument." << std::endl;
		break;
	case 2:
		std::wcout << L"Error code " << exitCode << L": bad arguments count." << std::endl;
		break;
	default:
		std::wcout << L"Error code " << exitCode << L": undefined error." << std::endl;
	}
}

void ReadAndEncodeData(std::wistream& stream)
{
	bool isError = false;
	std::wstring inStr;
	std::wstring outStr;
	while (!isError)
	{
		inStr = Mts::ReadLine(stream, isError);
		if (!inStr.empty())
		{
			outStr = HtmlEncode(inStr);
			std::wcout << outStr << std::endl;
		}
	}
}

std::wstring HtmlEncode(std::wstring const& text)
{
	std::wstring encodeStr;
	for (auto symbol : text)
	{
		switch (symbol)
		{
		case '\"':
			encodeStr += L"&quot;";
			break;
		case '\'':
			encodeStr += L"&apos;";
			break;
		case '<':
			encodeStr += L"&lt;";
			break;
		case '>':
			encodeStr += L"&gt;";
			break;
		case '&':
			encodeStr += L"&amp;";
			break;
		default:
			encodeStr.push_back(symbol);
		}
	}
	return encodeStr;
}