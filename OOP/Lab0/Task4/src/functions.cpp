#include "functions.hpp"

const float MAX_FLOAT = std::numeric_limits<float>::max();
const float MIN_FLOAT = std::numeric_limits<float>::min();

// print program info
void PrintProgramInfo(std::ostream& out)
{
	out << std::endl
		<< "Программа вычисляет результат арифметического выражения, операции и операнды которого передаются через аргументы командной строки. Поддерживаются следующие арифметические операции: сложение (+), вычитание (-), умножение (*) и деление (/). Вычисление выражения осуществляется без учета приоритета операторов." << std::endl
		<< std::endl;
	out << "Пример запуска программы: ./eval <number> <operation> <number> ... <operation> <number>" << std::endl
		<< std::endl;
}

// print program exit status
void PrintExitInfo(int exitCode, const std::string& msg, std::ostream& out)
{
	switch (exitCode)
	{
	case 0:
		out << std::endl;
		break;
	case 1:
		out << "Error code " << exitCode << ": bad arguments count." << std::endl;
		break;
	case 2:
		out << "Error code " << exitCode << ": bad arguments order." << std::endl;
		break;
	case 3:
		out << "Error code " << exitCode << ": argument '" << msg << "' is not allowed." << std::endl;
		break;
	case 4:
		out << "Error code " << exitCode << ": division by zero." << std::endl;
		break;
	case 5:
		out << "Error code " << exitCode << ": overflow detected." << std::endl;
		break;
	default:
		out << "Error code " << exitCode << ": undefined error." << std::endl;
	}
}

// add and check by exeption
int Addition(float operand1, float operand2, float& result)
{
	std::feclearexcept(FE_OVERFLOW);
	std::feclearexcept(FE_UNDERFLOW);

	result = operand1 + operand2;

	if ((bool)std::fetestexcept(FE_OVERFLOW) || (bool)std::fetestexcept(FE_UNDERFLOW))
	{
		return 5;
	}
	return 0;
}

// subtract and check by exeption
int Subtraction(float operand1, float operand2, float& result)
{
	std::feclearexcept(FE_OVERFLOW);
	std::feclearexcept(FE_UNDERFLOW);

	result = operand1 - operand2;

	if ((bool)std::fetestexcept(FE_OVERFLOW) || (bool)std::fetestexcept(FE_UNDERFLOW))
	{
		return 5;
	}
	return 0;
}

// multiply and check by exeption
int Multiplication(float operand1, float operand2, float& result)
{
	std::feclearexcept(FE_OVERFLOW);
	std::feclearexcept(FE_UNDERFLOW);

	result = operand1 * operand2;

	if ((bool)std::fetestexcept(FE_OVERFLOW) || (bool)std::fetestexcept(FE_UNDERFLOW))
	{
		return 5;
	}
	return 0;
}

// divide and check by exeption
int Division(float operand1, float operand2, float& result)
{
	std::feclearexcept(FE_OVERFLOW);
	std::feclearexcept(FE_UNDERFLOW);
	std::feclearexcept(FE_DIVBYZERO);

	result = operand1 / operand2;

	if ((bool)std::fetestexcept(FE_DIVBYZERO))
	{
		return 4;
	}
	else
	{
		if ((bool)std::fetestexcept(FE_OVERFLOW) || (bool)std::fetestexcept(FE_UNDERFLOW))
		{
			return 5;
		}
	}
	return 0;
}

//
int Calculate(char operation, float operand1, float operand2, float& result)
{
	switch (operation)
	{
	case '+':
		return Addition(operand1, operand2, result);
	case '-':
		return Subtraction(operand1, operand2, result);
	case '*':
		return Multiplication(operand1, operand2, result);
	case '/':
		return Division(operand1, operand2, result);
	default:
		return 3;
	}
	return 55;
}

// convert string to float number
bool StrToFloat(const std::string& str, float& number)
{
	try
	{
		number = std::stof(str);
	}
	catch (...)
	{
		return false;
	}
	return true;
}

// check allowed arguments (+f, -f, f, f..f, +, -, *, /)
int CheckArgument(const std::string& argument)
{
	int code = 0;
	int argLength = argument.size();
	if (argLength != 0)
	{
		bool isOperand = false;
		bool isOperator = false;
		bool isPoint = false;
		for (size_t i = 0; i < argLength; i++)
		{
			char ch = argument[i];
			if (ch >= '0' && ch <= '9' && !isOperator) // digit & not operator
			{
				isOperand = true;
				code = 1;
			}
			else
			{
				if (ch == '.' && isOperand && !isPoint) // first dot & operand
				{
					isPoint = true;
				}
				else
				{
					if ((ch == '+' || ch == '-' || ch == '*' || ch == '/') && i == 0) // operator & first symbol
					{
						code = 2;
						if (ch == '*' || ch == '/') // not allowed <*1.0> or </1.0> construction
						{
							isOperator = true;
						}
					}
					else
					{
						code = 0; // exit with error
						break;
					}
				}
			}
		}
	}
	return code;
}

int ApplyOperation(char operation, const std::string& argument, float& result, int argNum)
{
	int errCode = 3;
	float currOperand;
	if (StrToFloat(argument, currOperand))
	{
		if (argNum == 1) // result = first argument
		{
			result = currOperand;
			errCode = 0;
		}
		else // result = <result> <+|-|*|/> <currOperand>
		{
			errCode = Calculate(operation, result, currOperand, result);
		}
	}
	return errCode;
}
