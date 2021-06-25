#ifndef NUM_HPP
#define NUM_HPP

#include "locale.hpp"
#include <algorithm>
#include <limits>
#include <string>

namespace Mts
{

// INFINITY CONSTANTS =======================================================
constexpr float FINF = std::numeric_limits<float>::infinity();
constexpr double DINF = std::numeric_limits<double>::infinity();

// GET NUMBER SIGN ==========================================================
int GetSign(int number);
int GetSign(float number);
int GetSign(double number);

// GET ABSOLUTE =============================================================
int Abs(int number);
float Abs(float number);
double Abs(double number);

// MIN/MAX CONSTANTS ========================================================
const int INT_MIN = std::numeric_limits<int>::lowest();
const int INT_MAX = std::numeric_limits<int>::max();
constexpr float FLOAT_MIN = std::numeric_limits<float>::lowest();
constexpr float FLOAT_MAX = std::numeric_limits<float>::max();
constexpr double DOUBLE_MIN = std::numeric_limits<double>::lowest();
constexpr double DOUBLE_MAX = std::numeric_limits<double>::max();

// BITE SIZE CONSTANTS ======================================================
const int INT_BIT_SIZE = sizeof(int) * 8;
const int FLOAT_BIT_SIZE = sizeof(float) * 8;
const int DOUBLE_BIT_SIZE = sizeof(double) * 8;

// INTEGER CALCULATION ======================================================
int Add(int operand1, int operand2, bool& error);
int Sub(int operand1, int operand2, bool& error);
int Mul(int operand1, int operand2, bool& error);
int Div(int operand1, int operand2, bool& error);

// FLOAT CALCULATION ========================================================
float Add(float operand1, float operand2, bool& error);
float Sub(float operand1, float operand2, bool& error);
float Mul(float operand1, float operand2, bool& error);
float Div(float operand1, float operand2, bool& error);

// DOUBLE CALCULATION =======================================================
double Add(double operand1, double operand2, bool& error);
double Sub(double operand1, double operand2, bool& error);
double Mul(double operand1, double operand2, bool& error);
double Div(double operand1, double operand2, bool& error);

// FROM NUMBER TO STRING ====================================================
std::wstring IntToStr(int number, int radix, bool& error);
std::wstring IntToStr(int number);
std::wstring FloatToStr(float number);
std::wstring DoubleToStr(double number);
}

#endif // NUM_HPP
