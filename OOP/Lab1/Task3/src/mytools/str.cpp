#include "str.hpp"

// GET ARGUMENTS FROM COMMAND LINE ============================================
std::vector<std::wstring> Mts::GetArgs(char** argv, int argc)
{
	std::vector<std::wstring> container;
	for (int i = 0; i < argc; i++)
	{
		std::string str(argv[i]);
		std::wstring wstr = StrToWide(str);
		container.push_back(wstr);
	}
	return container;
}

// READ WSTRING FROM FILE =====================================================
std::wstring Mts::ReadLine(std::wifstream& file, bool& error)
{
	std::wstring line;
	if (!file.is_open())
		error = true;
	else if (file.eof())
		error = true;
	else
	{
		error = false;
		std::getline(file, line);
	}
	return line;
}

// PARSE WSTRING TO SUBSTRING =================================================
std::vector<std::wstring> Mts::ParseString(const std::wstring& wstring, wchar_t delimeter)
{
	wchar_t symb;
	std::wstring subStr;
	std::vector<std::wstring> container;
	int lastIndex = wstring.size() - 1;
	for (int i = 0; i <= lastIndex; i++)
	{
		symb = wstring[i];
		if (symb == delimeter)
		{
			if (!subStr.empty())
			{
				container.push_back(subStr);
				subStr.clear();
			}
		}
		else if (i == lastIndex)
		{
			subStr.push_back(symb);
			container.push_back(subStr);
		}
		else
		{
			subStr.push_back(symb);
		}
	}
	return container;
}

// CONVERT TO WIDE STRING =====================================================

std::wstring Mts::CharToWide(const char* array, int length)
{
	std::wstring wstring;
	for (int i = 0; i < length; i++)
	{
		wstring.push_back(std::use_facet<std::ctype<wchar_t>>(locale).widen(array[i]));
	}
	return wstring;
}

std::wstring Mts::StrToWide(const std::string& string)
{
	std::wstring wstring;
	for (int i = 0; i < string.size(); i++)
	{
		wstring.push_back(std::use_facet<std::ctype<wchar_t>>(locale).widen(string[i]));
	}
	return wstring;
}

// CONVERT WSTRING TO NUMBER ==================================================

int Mts::StrToInt(const std::wstring& wstring, int radix, bool& error)
{
	int number = 0;
	error = false;
	size_t pos;
	try
	{
		number = std::stoi(wstring, &pos, radix);
		if (pos != wstring.size())
			error = true;
	}
	catch (...)
	{
		error = true;
	}
	return number;
}

int Mts::StrToInt(const std::wstring& wstring, bool& error)
{
	return StrToInt(wstring, 10, error);
}

float Mts::StrToFloat(const std::wstring& wstring, bool& error)
{
	float number = 0;
	error = false;
	if (!IsFloat(wstring))
		error = true;
	else
	{
		try
		{
			number = std::stof(wstring);
		}
		catch (...)
		{
			error = true;
		}
	}
	return number;
}

double Mts::StrToDouble(const std::wstring& wstring, bool& error)
{
	double number = 0;
	error = false;
	if (!IsDouble(wstring))
		error = true;
	else
	{
		try
		{
			number = std::stod(wstring);
		}
		catch (...)
		{
			error = true;
		}
	}
	return number;
}

// IS NUMBER ==================================================================

// (+/-)<d>
bool Mts::IsInt(const std::wstring& wstring)
{
	bool result = true;
	bool digit = false;
	wchar_t symbol;
	for (int i = 0; i < wstring.size(); i++)
	{
		symbol = wstring[i];
		if (iswdigit(symbol))
		{
			digit = true;
		}
		else if (i != 0)
		{
			result = false;
			break;
		}
		else if (symbol != '+' && symbol != '-')
		{
			result = false;
			break;
		}
	}
	return digit && result;
}

// (+/-)(.|d)<d>(.|d)(d)
bool Mts::IsFloat(const std::wstring& wstring)
{
	bool result = true;
	bool digit = false;
	bool point = false;
	wchar_t symbol;
	for (int i = 0; i < wstring.size(); i++)
	{
		symbol = wstring[i];
		if (iswdigit(symbol))
		{
			digit = true;
		}
		else
		{
			switch (symbol)
			{
			case '.':
			case ',':
				if (!point)
				{
					point = true;
					break;
				}
			case '-':
			case '+':
				if (i == 0)
				{
					break;
				}
			default:
				result = false;
			}
		}
		if (!result)
			break;
	}
	return digit && result;
}

bool Mts::IsDouble(const std::wstring& wstring)
{
	return IsFloat(wstring);
}

// ============================================================================
