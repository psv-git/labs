#include "num.hpp"

using namespace Mts;

// GET NUMBER SIGN ============================================================

int Mts::GetSign(int number)
{
	return (number > 0) - (number < 0);
}

int Mts::GetSign(float number)
{
	return (number > 0) - (number < 0);
}

int Mts::GetSign(double number)
{
	return (number > 0) - (number < 0);
}

// GET ABSOLUTE ===============================================================

int Mts::Abs(int number)
{
	return number * ((number > 0) - (number < 0));
}

float Mts::Abs(float number)
{
	return number * ((number > 0) - (number < 0));
}

double Mts::Abs(double number)
{
	return number * ((number > 0) - (number < 0));
}

// INTEGER CALCULATION ========================================================

int Mts::Add(int operand1, int operand2, bool& error)
{
	error = false;
	int result = 0;
	if (operand2 > 0)
	{
		if (operand1 > INT_MAX - operand2)
			error = true;
	}
	else if (operand2 < 0)
	{
		if (operand1 < INT_MIN - operand2)
			error = true;
	}
	if (!error)
		result = operand1 + operand2;
	return result;
}

int Mts::Sub(int operand1, int operand2, bool& error)
{
	error = false;
	int result = 0;
	if (operand2 < 0)
	{
		if (operand1 > INT_MAX + operand2)
			error = true;
	}
	else if (operand2 > 0)
	{
		if (operand1 < INT_MIN + operand2)
			error = true;
	}
	if (!error)
		result = operand1 - operand2;
	return result;
}

int Mts::Mul(int operand1, int operand2, bool& error)
{
	error = false;
	int result = 0;
	int sign = GetSign(operand1) * GetSign(operand2);
	if (sign > 0)
	{
		if (operand1 > 0)
		{
			if (operand1 > INT_MAX / operand2)
				error = true;
		}
		else
		{
			if (operand1 == -1 || operand2 == -1)
			{
				if (operand1 < -INT_MAX || operand2 < -INT_MAX)
					error = true;
			}
			else if (operand1 < INT_MAX / operand2)
				error = true;
		}
	}
	else if (sign < 0)
	{
		if (operand1 > 0)
		{
			if (operand2 != -1)
			{
				if (operand1 > INT_MIN / operand2)
					error = true;
			}
		}
		else
		{
			if (operand1 < INT_MIN / operand2)
				error = true;
		}
	}
	if (!error)
		result = operand1 * operand2;
	return result;
}

// TODO: ДОБАВИТЬ ПОДДЕРЖКУ INT_MIN
int Mts::Div(int operand1, int operand2, bool& error)
{
	error = false;
	int result = 0;
	if (operand2 == 0)
		error = true;
	else if (operand1 < -INT_MAX)
		error = true;
	else
		result = operand1 / operand2;
	return result;
}

// FLOAT CALCULATION ========================================================

float Mts::Add(float operand1, float operand2, bool& error)
{
	error = false;
	float result = operand1 + operand2;
	if (result == FINF)
		error = true;
	else if (result == -FINF)
		error = true;
	return result;
}

float Mts::Sub(float operand1, float operand2, bool& error)
{
	error = false;
	float result = operand1 - operand2;
	if (result == FINF)
		error = true;
	else if (result == -FINF)
		error = true;
	return result;
}

float Mts::Mul(float operand1, float operand2, bool& error)
{
	error = false;
	float result = operand1 * operand2;
	if (result == FINF)
		error = true;
	else if (result == -FINF)
		error = true;
	return result;
}

float Mts::Div(float operand1, float operand2, bool& error)
{
	error = false;
	float result = operand1 / operand2;
	if (result == FINF)
		error = true;
	else if (result == -FINF)
		error = true;
	return result;
}

// DOUBLE CALCULATION =========================================================

double Mts::Add(double operand1, double operand2, bool& error)
{
	error = false;
	double result = operand1 + operand2;
	if (result == DINF)
		error = true;
	else if (result == -DINF)
		error = true;
	return result;
}

double Mts::Sub(double operand1, double operand2, bool& error)
{
	error = false;
	double result = operand1 - operand2;
	if (result == DINF)
		error = true;
	else if (result == -DINF)
		error = true;
	return result;
}

double Mts::Mul(double operand1, double operand2, bool& error)
{
	error = false;
	double result = operand1 * operand2;
	if (result == DINF)
		error = true;
	else if (result == -DINF)
		error = true;
	return result;
}

double Mts::Div(double operand1, double operand2, bool& error)
{
	error = false;
	double result = operand1 / operand2;
	if (result == DINF)
		error = true;
	else if (result == -DINF)
		error = true;
	return result;
}

// FROM NUMBER TO STRING ======================================================

std::wstring Mts::IntToStr(int number, int radix, bool& error)
{
	error = false;
	std::wstring wstr;
	if (radix < 2 || radix > 36)
		error = true;
	else
	{
		wchar_t digit[] = L"0123456789ABCDEFGHIJKLMNOPRSTUVWXYZ";
		bool negative = number < 0;
		int quot, rem;
		do
		{
			quot = number / radix;
			rem = number % radix;
			if (negative)
				wstr.push_back(digit[Abs(rem)]);
			else
				wstr.push_back(digit[rem]);
			number = quot;
		} while (number);
		if (negative)
			wstr.push_back('-');
		std::reverse(wstr.begin(), wstr.end());
	}
	return wstr;
}

std::wstring Mts::IntToStr(int number)
{
	return std::to_wstring(number);
}

std::wstring Mts::FloatToStr(float number)
{
	return std::to_wstring(number);
}

std::wstring Mts::DoubleToStr(double number)
{
	return std::to_wstring(number);
}

// ============================================================================
