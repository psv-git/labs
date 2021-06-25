#include "functions.hpp"

// print program info
void PrintProgramInfo()
{
	std::wcout << std::endl
			   << L"Программа выполняет считывание массива чисел с плавающей запятой, разделяемых пробелами, из стандартного потока ввода в vector, деление элементов массива на половину максимального элемента и выводит в стандартный поток полученный массив." << std::endl
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
		std::wcout << L"Error code " << exitCode << L": undefined argument." << std::endl;
		break;
	case 2:
		std::wcout << L"Error code " << exitCode << L": bad arguments count." << std::endl;
		break;
	case 3:
		std::wcout << L"Error code " << exitCode << L": bad input value." << std::endl;
		break;
	case 4:
		std::wcout << L"Error code " << exitCode << L": division by zero." << std::endl;
		break;
	default:
		std::wcout << L"Error code " << exitCode << L": undefined error." << std::endl;
	}
}

std::vector<double> GetVectorFromIstream(std::wistream& stream, bool& isError)
{
	isError = false;
	std::vector<double> doubleVector;
	std::wstring inputString = Mts::ReadLine(std::wcin, isError);
	if (!isError)
	{
		std::vector<std::wstring> stringVector = Mts::ParseString(inputString, ' ');
		double doubleValue;
		for (auto stringValue : stringVector)
		{
			doubleValue = Mts::StrToDouble(stringValue, isError);
			if (isError)
			{
				break;
			}
			doubleVector.push_back(doubleValue);
		}
	}
	return doubleVector;
}

double GetMaxValue(std::vector<double>& vector)
{
	return *std::max_element(vector.begin(), vector.end());
}

bool VectorProcessing(std::vector<double>& vector, double max)
{
	if (max != 0) {
		double halfMax = max / 2;
		std::transform(vector.begin(), vector.end(), vector.begin(), [&halfMax](double a) { return a / halfMax; });
		std::sort(vector.begin(), vector.end(), [](double a, double b) { return a < b; });
		return 0;
	}
	return 1;
}

void PrintVector(std::vector<double>& vector)
{
	for (auto& d : vector)
	{
		std::wcout << d << " ";
	}
	std::wcout << std::endl;
}