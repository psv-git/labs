#include "functions.hpp"

// print program info
void PrintProgramInfo()
{
	std::wcout << std::endl
			   << L"Программа-словарь, осуществляет перевод слов и словосочетаний, поступающих со стандартного потока ввода, с английского языка на русский с использованием заданного файла словаря и выводящая результат перевода в стандартный поток вывода." << std::endl
			   << std::endl;
	std::wcout << L"Пример запуска: task3 <dictionary file name>" << std::endl
			   << std::endl;
}

void PrintExitInfo(int exitCode)
{
	switch (exitCode)
	{
	case 0:
		break;
	case 1:
		std::wcout << L"Error code " << exitCode << L": bad dictionary file." << std::endl;
		break;
	case 2:
		std::wcout << L"Error code " << exitCode << L": saving dictionary file was failrd." << std::endl;
		break;
	default:
		std::wcout << L"Error code " << exitCode << L": undefined error." << std::endl;
	}
}

std::map<std::wstring, std::wstring> dictionary;

int CreateDictionary(std::wifstream& dictionaryFile)
{
	bool isError = false;
	std::wstring pairString;
	std::vector<std::wstring> pairContainer;
	dictionaryFile.imbue(std::locale("ru_RU.UTF-8"));
	while (!isError)
	{
		pairString = Mts::ReadLine(dictionaryFile, isError);
		if (!isError && !pairString.empty())
		{
			pairContainer = Mts::ParseString(pairString, ' ');
			if (pairContainer.size() != 2)
			{
				return 1;
			}
			dictionary.insert(std::pair<std::wstring, std::wstring>(pairContainer.at(0), pairContainer.at(1)));
		}
	}
	return 0;
}

std::wstring CheckTranslate(const std::wstring& inputString)
{
	std::wstring translatedString;
	auto it = dictionary.find(inputString);
	if (it != dictionary.end())
	{
		translatedString = (*it).second;
	}
	return translatedString;
}

void AddTranslate(const std::wstring& inputString, const std::wstring& translatedString)
{
	dictionary.insert(std::pair<std::wstring, std::wstring>(inputString, translatedString));
	return;
}

int SaveDictionary(const std::string& dictionaryPath)
{
	std::wofstream dictionaryFile(dictionaryPath, std::wios::out);
	dictionaryFile.imbue(std::locale("ru_RU.UTF-8"));
	if (!dictionaryFile.is_open())
	{
		return 2;
	}
	for (auto it = dictionary.begin(); it != dictionary.end(); it++)
	{
		dictionaryFile << (*it).first << L" " << (*it).second << std::endl;
	}
	dictionaryFile.close();
	return 0;
}
