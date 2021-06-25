#include "functions.hpp"

// print program info
void PrintProgramInfo()
{
	std::wcout << std::endl;
	std::wcout << L"Приложение выполняет инвертирование матрицы 3*3, т.е. нахождение обратной матрицы и выводит коэффициенты результирующей матрицы в стандартный поток вывода." << std::endl
			   << std::endl;
	std::wcout << L"Пример запуска программы: invert <matrix file>" << std::endl
			   << std::endl;
}

// print program exit status
void PrintExitInfo(int exitCode)
{
	switch (exitCode)
	{
	case 0:
		break;
	case 1:
		std::wcout << L"Error code " << exitCode << L": bad arguments count." << std::endl;
		break;
	case 2:
		std::wcout << L"Error code " << exitCode << L": input file was not open." << std::endl;
		break;
	case 3:
		std::wcout << L"Error code " << exitCode << L": read line from input file was failed." << std::endl;
		break;
	case 4:
		std::wcout << L"Error code " << exitCode << L": bad count matrix columns." << std::endl;
		break;
	case 5:
		std::wcout << L"Error code " << exitCode << L": bad coefficient value." << std::endl;
		break;
	case 6:
		std::wcout << L"Error code " << exitCode << L": input file is empty." << std::endl;
		break;
	case 7:
		std::wcout << L"Error code " << exitCode << L": bad count matrix rows." << std::endl;
		break;
	case 8:
		std::wcout << L"Error code " << exitCode << L": matrix can not be inverted." << std::endl;
		break;
	default:
		std::wcout << L"Error code " << exitCode << L": undefined error." << std::endl;
	}
}

// get matrix [matrixSize*matrixSize] from input file
int GetMatrixFromFile(std::wifstream& inFile, float matrix[][MATRIX_DIMENSION])
{
	bool isError;
	int size = MATRIX_DIMENSION;
	std::wstring line;
	std::vector<std::wstring> coefs;
	int row = 0;
	while (!inFile.eof())
	{
		line = Mts::ReadLine(inFile, isError);
		if (isError)
		{
			return 3;
		}
		coefs = Mts::ParseString(line, ' ');
		if (!coefs.empty())
		{
			if (row == size)
			{
				row++;
				break;
			}
			if (coefs.size() != size)
			{
				return 4;
			}
			for (int col = 0; col < size; col++)
			{
				matrix[row][col] = Mts::StrToFloat(coefs[col], isError);
				if (isError)
				{
					return 5;
				}
			}
			row++;
		}
	}
	if (row == 0)
		return 6;
	if (row != size)
		return 7;
	return 0;
}

int GetDeterminant(float matrix[][MATRIX_DIMENSION])
{
	return matrix[0][0] * matrix[1][1] * matrix[2][2] + matrix[0][1] * matrix[1][2] * matrix[2][0] + matrix[0][2] * matrix[1][0] * matrix[2][1] - matrix[0][2] * matrix[1][1] * matrix[2][0] - matrix[0][0] * matrix[1][2] * matrix[2][1] - matrix[0][1] * matrix[1][0] * matrix[2][2];
}

void GetMinorMatrix(float sourceMatrix[][MATRIX_DIMENSION], float minorMatrix[][MATRIX_DIMENSION])
{
	int subMatrixIndex = 0;
	float subMatrix[MATRIX_DIMENSION + 1];
	for (int row = 0; row < MATRIX_DIMENSION; row++)
	{
		for (int col = 0; col < MATRIX_DIMENSION; col++)
		{
			for (int i = 0; i < MATRIX_DIMENSION * MATRIX_DIMENSION; i++)
			{
				if (i / MATRIX_DIMENSION != row && i % MATRIX_DIMENSION != col)
				{
					subMatrix[subMatrixIndex] = sourceMatrix[i / MATRIX_DIMENSION][i % MATRIX_DIMENSION];
					subMatrixIndex++;
				}
			}
			minorMatrix[row][col] = subMatrix[0] * subMatrix[3] - subMatrix[1] * subMatrix[2];
			subMatrixIndex = 0;
		}
	}
}

void GetComplementMatrix(float minorMatrix[][MATRIX_DIMENSION])
{
	for (int row = 0; row < MATRIX_DIMENSION; row++)
	{
		for (int col = 0; col < MATRIX_DIMENSION; col++)
		{
			if ((row * MATRIX_DIMENSION + col) % 2 != 0)
			{
				minorMatrix[row][col] = 0.0f - minorMatrix[row][col];
			}
		}
	}
}

void GetAdjugateMatrix(float minorMatrix[][MATRIX_DIMENSION])
{
	int i = MATRIX_DIMENSION - 1;
	for (int row = 0; row < MATRIX_DIMENSION; row++)
	{
		for (int col = MATRIX_DIMENSION - i; col < MATRIX_DIMENSION; col++)
		{
			int swap = minorMatrix[row][col];
			minorMatrix[row][col] = minorMatrix[col][row];
			minorMatrix[col][row] = swap;
		}
		i--;
	}
}

void GetInverseMatrix(float sourceMatrix[][MATRIX_DIMENSION], float minorMatrix[][MATRIX_DIMENSION], float determinant)
{
	for (int row = 0; row < MATRIX_DIMENSION; row++)
	{
		for (int col = 0; col < MATRIX_DIMENSION; col++)
		{
			sourceMatrix[row][col] = minorMatrix[row][col] * (1.0f / determinant);
		}
	}
}

int InverseMatrix(float matrix[][MATRIX_DIMENSION])
{
	// get determinant
	int determinant = GetDeterminant(matrix);
	if (determinant == 0)
		return 8;
	float minorMatrix[MATRIX_DIMENSION][MATRIX_DIMENSION];
	GetMinorMatrix(matrix, minorMatrix);
	GetComplementMatrix(minorMatrix);
	GetAdjugateMatrix(minorMatrix);
	GetInverseMatrix(matrix, minorMatrix, determinant);
	return 0;
}

// print matrix to output
void PrintMatrix(float matrix[][MATRIX_DIMENSION])
{
	int size = MATRIX_DIMENSION;
	for (int row = 0; row < size; row++)
	{
		for (int col = 0; col < size; col++)
		{
			//std::wcout << std::setw(10) << std::left << matrix[row][col];
			std::wcout << matrix[row][col] << " ";
		}
		//std::wcout << std::endl;
	}
}
