#include "stdafx.h"

const int STR_LENGTH = 5; // length output string
const int MAX_INT = std::numeric_limits<int>::max();

// print error message to outstream
void PrintError(int errCode, std::ostream& out)
{
	switch (errCode)
	{
	case 1:
		out << "Error: argument not found." << std::endl;
		break;
	case 2:
		out << "Error: argument is not allowable number." << std::endl;
		break;
	case 3:
		out << std::endl
			<< std::endl
			<< "Error: addition owerflow detected." << std::endl;
		break;
	default:
		out << "Error: undefined error." << std::endl;
	}
}

// convert string to number
int StrToInt(const char* str, bool& err)
{
	char* pLastChar = nullptr;
	int num = strtol(str, &pLastChar, 10);
	err = ((*str == '\0') || (*pLastChar != '\0'));
	return num;
}

// add two numbers and check by owerflow
int NumbersAddition(int prevNum, int currNum)
{
	int num = MAX_INT - prevNum;
	if (num < currNum)
	{
		return -1; // return overflow
	}
	else
	{
		return prevNum + currNum; // return numbers summ
	}
}

// print Fibonacci sequence to outstream
void PrintFibonacciSeq(int prevNum, int currNum, int maxNum, int symCount, std::ostream& out)
{
	out << prevNum;
	bool isStop = currNum > maxNum; // escape condition

	if (symCount < STR_LENGTH && !isStop) // not write ',' to rows end
	{
		out << ", ";
	}
	else
	{
		out << std::endl;
		symCount = 0;
	}

	if (!isStop)
	{
		symCount++;
		int nextNum = NumbersAddition(prevNum, currNum);
		if (nextNum >= 0)
		{
			PrintFibonacciSeq(currNum, nextNum, maxNum, symCount, out);
		}
		else
		{
			PrintError(3, std::cerr);
		}
	}
}

int main(int argc, char* argv[])
{
	std::cout << std::endl;
	if (argc > 1)
	{
		bool err = true;
		int num = StrToInt(argv[1], err);
		if (!err && num > 0)
		{
			PrintFibonacciSeq(0, 1, num, 1, std::cout);
		}
		else
		{
			PrintError(2, std::cerr);
		}
	}
	else
	{
		PrintError(1, std::cerr);
	}

	std::cout << std::endl;
	return 0;
}
