#include "stdafx.h"
#include "../libs/functions.hpp"

int main(int argc, char* argv[])
{
	Mts::SetLocale("ru");
	std::wcout.setf(std::ios::fixed);
	std::wcout.precision(3);

	// print help
	if (argc == 2)
	{
		std::string arg(argv[1]);
		if (arg == "--help" || arg == "-h")
		{
			PrintProgramInfo();
			return 0; // print program info
		}
		PrintExitInfo(1);
		return 1; // undefined argument
	}

	if (argc > 2)
	{
		PrintExitInfo(2);
		return 2; // bad arguments count
	}

	// get vector from input
	std::wcout << L"Введите значения вектора, разделяя пробелами: ";
	bool isError;
	std::vector<double> numbers = GetVectorFromIstream(std::wcin, isError);
	if (isError)
	{
		PrintExitInfo(3);
		return 3;
	}

	double maxValue = GetMaxValue(numbers);
	if (VectorProcessing(numbers, maxValue)) {
		PrintExitInfo(4);
		return 4; // bad arguments count
	}
	PrintVector(numbers);

	return 0;
}
