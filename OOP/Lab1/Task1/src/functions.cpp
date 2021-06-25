#include "functions.hpp"

// print program info
void PrintProgramInfo(std::ostream& out)
{
	out << std::endl
		<< "Программа выполняет замену всех вхождений подстроки в текстовом файле на другую строку, и записывает результат в выходной файл (отличный от входного). " << std::endl
		<< std::endl;
	out << "Пример запуска программы: ./replace <input file> <output file> <search string> <replace string>" << std::endl
		<< std::endl;
}

// print program exit status
void PrintExitInfo(int exitCode, std::ostream& out)
{
	switch (exitCode)
	{
	case 0:
		break;
	case 1:
		out << "Error code " << exitCode << ": bad arguments count." << std::endl;
		break;
	case 2:
		out << "Error code " << exitCode << ": error opening input file." << std::endl;
		break;
	case 3:
		out << "Error code " << exitCode << ": error opening output file." << std::endl;
		break;
	case 4:
		out << "Error code " << exitCode << ": search string is empty." << std::endl;
		break;
	default:
		out << "Error code " << exitCode << ": undefined error." << std::endl;
	}
}

// get line from file
std::string GetLine(std::fstream& file)
{
	std::string str;
	if (!file.eof())
	{
		char ch = file.get();
		while (!file.eof())
		{
			str += ch;
			if (ch == '\n')
			{
				break;
			}
			ch = file.get();
		}
	}
	return str;
}

// copy input file to output file with replace string
std::string ReplaceString(const std::string &inString, const std::string& searchString, const std::string& replaceString)
{
	std::string outString;
	std::size_t begin = 0;
	std::size_t end = inString.find(searchString, begin);
	while (end != std::string::npos)
	{
		outString.append(inString, begin, end - begin);
		outString += replaceString;
		begin = end + searchString.size();
		end = inString.find(searchString, begin);
	}
	outString.append(inString, begin, inString.size());

	return outString;
}
