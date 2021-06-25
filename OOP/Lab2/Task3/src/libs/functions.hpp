#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include "../task/stdafx.h"

void PrintProgramInfo();
void PrintExitInfo(int exitCode);
int CreateDictionary(std::wifstream& dictionaryFile);
std::wstring CheckTranslate(const std::wstring& inputString);
void AddTranslate(const std::wstring& inputString, const std::wstring& translatedString);
int SaveDictionary(const std::string& dictionaryPath);

#endif // FUNCTIONS_HPP
