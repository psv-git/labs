#include "stdafx.h"
#include "functions.hpp"

const char DATA_PATH[] = "data/";

int main(int argc, char* argv[])
{
	int exitCode = 0;
	if (argc < 2)
	{
		PrintProgramInfo(std::cout);
	}
	else
	{
		if (argc == 5)
		{
			std::string path(DATA_PATH + std::string(argv[1]));
			std::fstream inFile(path.c_str(), std::ios::in);
			if (!inFile.is_open())
			{
				exitCode = 2; // error open input file
			}
			else
			{
				path = DATA_PATH + std::string(argv[2]);
				std::fstream outFile(path.c_str(), std::ios::out);
				if (!outFile.is_open())
				{
					exitCode = 3; // error open output file
				}
				else
				{
					std::string sString(argv[3]);
					if (sString.size() < 1)
					{
						exitCode = 4; // error emty search string
					}
					else
					{
						std::string rString(argv[4]);
						std::string inStr; // string from inFile
						std::string outStr; // string to outFile
						while (!inFile.eof())
						{
							inStr = GetLine(inFile);
							outStr.clear();
							outStr = ReplaceString(inStr, sString, rString);
							outFile << outStr;
						}
					}
				}
			}
		}
		else
		{
			exitCode = 1; // error ban arguments count
		}
	}

	PrintExitInfo(exitCode, std::cout);

	return exitCode;
}
