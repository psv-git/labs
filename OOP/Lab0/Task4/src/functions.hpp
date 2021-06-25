#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "stdafx.h"

void PrintProgramInfo(std::ostream& out);
void PrintExitInfo(int errCode, const std::string& msg, std::ostream& out);
int Addition(float operand1, float operand2, float& result);
int Subtraction(float operand1, float operand2, float& result);
int Multiplication(float operand1, float operand2, float& result);
int Division(float operand1, float operand2, float& result);
int Calculate(char operation, float operand1, float operand2, float& result);
bool StrToFloat(const std::string& str, float& number);
int CheckArgument(const std::string& argument);
int ApplyOperation(char operation, const std::string& argument, float& result, int argNum);

#endif // FUNCTIONS_H
