#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include "../task/stdafx.h"

void PrintProgramInfo();
void PrintExitInfo(int exitCode);
void ReadAndEncodeData(std::wistream& stream);
std::wstring HtmlEncode(std::wstring const& text);

#endif // FUNCTIONS_HPP
