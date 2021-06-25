#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "stdafx.h"

void PrintProgramInfo();
void PrintExitInfo(int exitCode);
int PackingFile(std::ifstream& inFile, std::ofstream& outFile);
int UnpackingFile(std::ifstream& inFile, std::ofstream& outFile);

#endif // FUNCTIONS_H
