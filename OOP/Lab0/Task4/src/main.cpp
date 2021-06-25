#include "stdafx.h"
#include "functions.hpp"

int main(int argc, char* argv[])
{
	std::cout.setf(std::ios::fixed);
	std::cout.precision(3);
	int exitCode = 0;
	std::string argument; // current argument
	if (argc < 2)
	{
		PrintProgramInfo(std::cout);
	}
	else
	{
		if ((argc - 1) % 2 != 0)
		{
			bool argOrder = false; // true => operand, false => operator
			float result = 0; // output value
			float currOperand = 0; // current operand
			char currOperation; // current operation
			for (size_t i = 1; i < argc; i++)
			{
				if (exitCode != 0) // have error => exit
				{
					break;
				}
				argument = argv[i];
				int validState = CheckArgument(argument); // argument validation
				switch (validState)
				{
				case 0:
					exitCode = 3; // argument not allowed => exitCode 3
					break;
				case 1: // argument is operand
					exitCode = 2;
					if (!argOrder) // odd argument => correct order
					{
						exitCode = ApplyOperation(argv[i - 1][0], argument, result, i);
					}
					argOrder = !argOrder;
					break;
				case 2: // argument is operation
					if (!argOrder)
					{
						exitCode = 2; // bad argument order => exitCode 2
					}
					argOrder = !argOrder;
					break;
				}
			}
			if (exitCode == 0) // print result
			{
				std::cout << result;
			}
		}
		else
		{
			exitCode = 1; // odd arguments count => exitCode 1
		}
	}

	PrintExitInfo(exitCode, argument, std::cout);

	return exitCode;
}
