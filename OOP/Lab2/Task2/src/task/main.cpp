#include "stdafx.h"
#include "../libs/functions.hpp"

int main(int argc, char* argv[])
{
	Mts::SetLocale("ru");

	// check args
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
	else if (argc > 2)
	{
		PrintExitInfo(2);
		return 2; // bad arguments count
	}

	ReadAndEncodeData(std::wcin);

	return 0;
}
