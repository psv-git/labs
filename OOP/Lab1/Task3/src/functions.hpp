#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "stdafx.h"

const int MATRIX_DIMENSION = 3;

void PrintProgramInfo();
void PrintExitInfo(int exitCode);
int GetMatrixFromFile(std::wifstream& inFile, float matrix[][MATRIX_DIMENSION]);
int GetDeterminant(float matrix[][MATRIX_DIMENSION]);
void GetMinorMatrix(float sourceMatrix[][MATRIX_DIMENSION], float minorMatrix[][MATRIX_DIMENSION]);
void GetComplementMatrix(float minorMatrix[][MATRIX_DIMENSION]);
void GetAdjugateMatrix(float minorMatrix[][MATRIX_DIMENSION]);
void GetInverseMatrix(float sourceMatrix[][MATRIX_DIMENSION], float minorMatrix[][MATRIX_DIMENSION], float determinant);
int InverseMatrix(float matrix[][MATRIX_DIMENSION]);
void PrintMatrix(float matrix[][MATRIX_DIMENSION]);

#endif // FUNCTIONS_H
