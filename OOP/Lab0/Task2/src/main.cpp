#include "stdafx.h"

const int DEFAULT_LIMIT = 1000;

// summ number digits
int SumDigits(int i)
{
	int sum = 0;
	while (i != 0)
	{
		sum += i % 10;
		i /= 10;
	}
	return sum;
}

// convert string to number
int StrToInt(const char* str, bool& err)
{
	char* pLastChar = nullptr;
	int num = strtol(str, &pLastChar, 10);
	err = ((*str == '\0') || (*pLastChar != '\0'));
	return num;
}

int main(int argc, char* argv[])
{
	int lim = DEFAULT_LIMIT;
	std::cout << std::endl;

	if (argc > 1) // check arg
	{
		bool err = true;
		int num = StrToInt(argv[1], err);
		if (!err && num > 0)
		{
			lim = num;
		}
		else
		{
			std::cerr << "Error: argument is not allowable number." << std::endl
					  << std::endl;
		}
	}

	for (size_t i = 1; i < lim + 1; i++)
	{
		if (i % SumDigits(i) == 0)
		{
			std::cout << i << " ";
		}
	}

	std::cout << std::endl
			  << std::endl;
	return 0;
}
