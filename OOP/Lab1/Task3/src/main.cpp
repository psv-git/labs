#include "stdafx.h"
#include "functions.hpp"

const char DATA_PATH[] = "data/";

int main(int argc, char* argv[])
{
	Mts::SetLocale("ru");
	std::wcout.setf(std::ios::fixed);
	std::wcout.precision(3);

	// run without arguments
	if (argc < 2)
	{
		PrintProgramInfo();
		return 0;
	}

	// bad arguments count
	if (argc != 2)
	{
		PrintExitInfo(1);
		return 1;
	}

	// get input file
	std::wifstream inFile(DATA_PATH + std::string(argv[1]), std::ios::in);
	if (!inFile.is_open())
	{
		PrintExitInfo(2);
		return 2;
	}

	float matrix[MATRIX_DIMENSION][MATRIX_DIMENSION];
	// get matrix from file
	int errCode = GetMatrixFromFile(inFile, matrix);
	if (errCode != 0)
	{
		PrintExitInfo(errCode);
		return errCode;
	}

	// get inverse matrix
	errCode = InverseMatrix(matrix);
	if (errCode != 0)
	{
		PrintExitInfo(errCode);
		return errCode;
	}

	// print matrix to output
	PrintMatrix(matrix);

	return 0;
}
