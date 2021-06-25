#include "stdafx.h"
#include "functions.hpp"

const char DATA_PATH[] = "data/";

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

	// open input file
	std::ifstream inFile(DATA_PATH + std::string(argv[2]), std::ios::binary);
	if (!inFile.is_open())
	{
		PrintExitInfo(2);
		return 2;
	}

	// open output file
	std::ofstream outFile(DATA_PATH + std::string(argv[3]), std::ios::binary);
	if (!outFile.is_open())
	{
		PrintExitInfo(3);
		return 3;
	}

	std::string mode(argv[1]);
	int operationState;
	if (mode == "pack")
	{
		operationState = PackingFile(inFile, outFile);
	}
	else if (mode == "unpack")
	{
		operationState = UnpackingFile(inFile, outFile);
	}
	else
	{
		PrintExitInfo(4);
		return 4;
	}

	PrintExitInfo(operationState);
	return operationState;
}
