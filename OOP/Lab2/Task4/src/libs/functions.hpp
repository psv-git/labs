#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include "../task/stdafx.h"

void PrintProgramInfo();
void PrintExitInfo(int exitCode);
int GetN(const std::wstring &nString);
std::set<int> MakeFirstSet(int N);
std::set<int> MakeSecondSet(int N);
std::set<int> CrossSet(std::set<int> const &set1, std::set<int> const &set2);
void PrintSet(const std::set<int> &set);

#endif // FUNCTIONS_HPP
