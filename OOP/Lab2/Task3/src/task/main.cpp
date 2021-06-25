#include "stdafx.h"
#include "../libs/functions.hpp"

const char DATA_PATH[] = "data/";

int main(int argc, char* argv[])
{
	Mts::SetLocale("ru");

	// check args
	if (argc != 2)
	{
		PrintProgramInfo();
		return 0;
	}

	// open dictionary file
	std::string dictionaryPath(DATA_PATH + std::string(argv[1]));
	std::wifstream dictionaryFile(dictionaryPath, std::ios::in);

	// create temp dictionary in memory
	int code = CreateDictionary(dictionaryFile);
	if (code != 0)
	{
		PrintExitInfo(code);
		return code;
	}

	// run application loop
	bool isDictionaryChanged = false;
	std::wstring inputString;
	std::wstring translatedString;
	while (true)
	{
		std::wcout << L">";
		std::getline(std::wcin, inputString);
		if (inputString == L"...")
		{
			break;
		}
		if (inputString.empty())
		{
			continue;
		}
		translatedString = CheckTranslate(inputString);
		if (translatedString.empty())
		{
			std::wcout << L"Неизвестное слово \"" << inputString << L"\". Введите перевод или пустую строку для отказа." << std::endl
					   << L">";
			std::getline(std::wcin, translatedString);
			if (translatedString.empty())
			{
				std::wcout << L"Слово \"" << inputString << L"\" проигнорировано." << std::endl;
			}
			else
			{
				isDictionaryChanged = true;
				AddTranslate(inputString, translatedString);
				std::wcout << L"Слово \"" << inputString << L"\" сохранено в словаре как \"" << translatedString << L"\"." << std::endl;
			}
		}
		else
		{
			std::wcout << translatedString << std::endl;
		}
	}

	// save dictionary
	if (isDictionaryChanged)
	{
		wchar_t wch;
		std::wcout << L"В словарь были внесены изменения. Введите Y или y для сохранения перед выходом." << std::endl
				   << L">";
		std::wcin.get(wch);
		if (wch == 'Y' || wch == 'y')
		{
			if (dictionaryFile.is_open())
			{
				dictionaryFile.close();
			}
			int code = SaveDictionary(dictionaryPath);
			if (code != 0)
			{
				PrintExitInfo(code);
				return code;
			}
			std::wcout << L"Изменения сохранены. До свидания." << std::endl;
		}
	}

	return 0;
}
