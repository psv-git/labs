#include "functions.hpp"

// print program info
void PrintProgramInfo()
{
	std::wcout << std::endl;
	std::wcout << L"Программа выполняет перевод чисел из одной произвольной системы счисления в другую произвольную и запись результата в стандартный поток вывода. Под произвольной системой счисления понимается система с основанием от 2 до 36." << std::endl
			   << std::endl;
	std::wcout << L"Пример запуска программы: radix <source notation> <destination notation> <value>" << std::endl
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
		std::wcout << L"Error code " << exitCode << L": bad source radix." << std::endl;
		break;
	case 3:
		std::wcout << L"Error code " << exitCode << L": bad dest radix." << std::endl;
		break;
	case 4:
		std::wcout << L"Error code " << exitCode << L": convert number to source radix was failed." << std::endl;
		break;
	case 5:
		std::wcout << L"Error code " << exitCode << L": convert number to dest radix was failed." << std::endl;
		break;
	default:
		std::wcout << L"Error code " << exitCode << L": undefined error." << std::endl;
	}
}
