#include "stdafx.h"
#include "functions.hpp"

int main(int argc, char* argv[])
{
	Mts::SetLocale("ru");

	// run without arguments
	if (argc < 2)
	{
		PrintProgramInfo();
		return 0;
	}

	// bad arguments count
	if (argc != 4)
	{
		PrintExitInfo(1);
		return 1;
	}

	std::vector<std::wstring> args = Mts::GetArgs(argv, argc);
	bool isError;
	int sourceRadix, destRadix, number;
	std::wstring outStr;

	// get source radix
	sourceRadix = Mts::StrToInt(args[1], isError);
	if (isError || sourceRadix < 2 || sourceRadix > 36)
	{
		PrintExitInfo(2);
		return 2;
	}

	// get dest radix
	destRadix = Mts::StrToInt(args[2], isError);
	if (isError || destRadix < 2 || destRadix > 36)
	{
		PrintExitInfo(3);
		return 3;
	}

	// get number by source radix
	number = Mts::StrToInt(args[3], sourceRadix, isError);
	if (isError)
	{
		PrintExitInfo(4);
		return 4;
	}

	// get out string by number
	outStr = Mts::IntToStr(number, destRadix, isError);
	if (isError)
	{
		PrintExitInfo(5);
		return 5;
	}

	std::wcout << outStr << std::endl;

	return 0;
}
