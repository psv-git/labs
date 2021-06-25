#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "stdafx.h"

void PrintProgramInfo(std::ostream& out);
void PrintExitInfo(int errCode, std::ostream& out);
std::string ReplaceString(const std::string &inString, const std::string& searchString, const std::string& replaceString);
std::string GetLine(std::fstream& file);

#endif // FUNCTIONS_H
