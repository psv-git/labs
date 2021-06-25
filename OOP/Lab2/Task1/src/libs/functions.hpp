#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include "../task/stdafx.h"

void PrintProgramInfo();
void PrintExitInfo(int exitCode);
std::vector<double> GetVectorFromIstream(std::wistream& stream, bool& isError);
double GetMaxValue(std::vector<double>& vector);
bool VectorProcessing(std::vector<double>& vector, double max);
void PrintVector(std::vector<double>& vector);

#endif // FUNCTIONS_HPP
