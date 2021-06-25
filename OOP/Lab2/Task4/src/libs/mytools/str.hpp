#ifndef STR_HPP
#define STR_HPP

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

namespace Mts {

// GET ARGUMENTS FROM COMMAND LINE ==========================================
std::vector<std::wstring> GetArgs(char *argv[], int argc);

// READ WSTRING FROM STREAM =================================================
std::wstring ReadLine(std::wifstream &file, bool &isError);
std::wstring ReadLine(std::wistream &stream, bool &isError);

// PARSE WSTRING TO SUBSTRING ===============================================
std::vector<std::wstring> ParseString(const std::wstring &wstring,
                                      wchar_t delimeter);

// CONVERT TO WIDE STRING ========================================
std::wstring CharToWide(const char *array, int length);
std::wstring CharToWide(const char *string);
std::wstring StrToWide(const std::string &wstring);

// CONVERT WSTRING TO NUMBER ========================================
int StrToInt(const std::wstring &wstring, int radix, bool &isError);
int StrToInt(const std::wstring &wstring, bool &isError);
double StrToDouble(const std::wstring &wstring, bool &isError);
}

#endif // STR_HPP
