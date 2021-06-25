#include "functions.hpp"

double ReadDouble(std::istream& stream)
{
	double val = 0;
	stream >> val;
	if (stream.fail())
	{
		throw std::invalid_argument("Non-integer data encountered.");
	}
	return val;
}

double AddDoubles(double v1, double v2)
{
	double res = v1 + v2;
	if (std::isinf(res))
	{
		throw std::overflow_error("Overflow was detected in AddDoubles().");
	}
	return res;
}

double SubDoubles(double v1, double v2)
{
	double res = v1 - v2;
	if (std::isinf(res))
	{
		throw std::overflow_error("Overflow was detected in SubDoubles().");
	}
	return res;
}

double MulDoubles(double v1, double v2)
{
	double res = v1 * v2;
	if (std::isinf(res))
	{
		throw std::overflow_error("Overflow was detected in MulDoubles().");
	}
	return res;
}

double DivDoubles(double v1, double v2)
{
	if (v2 == 0)
	{
		throw std::invalid_argument("Division by zero in DivDoubles().");
	}
	double res = v1 / v2;
	if (std::isinf(res))
	{
		throw std::overflow_error("Overflow was detected in DivDoubles().");
	}
	return res;
}

double Atan2(double v1, double v2)
{
	std::feclearexcept(FE_ALL_EXCEPT);
	errno = 0;
	double res = std::atan2(v1, v2);
	if (errno != 0 && std::fetestexcept(FE_ALL_EXCEPT))
	{
		throw std::invalid_argument("Exception was detected in Atan2().");
	}
	return res;
}

bool NumbersAreEqual(double v1, double v2)
{
	return std::fabs(SubDoubles(v1, v2)) < D_EPS;
}
