#include "stdafx.h"
#include "../libs/CHttpUrl.hpp"

int main(int argc, char* argv[])
{
	std::ifstream inFile("./data/input1", std::ios::in);
	if (!inFile.is_open())
		std::cout << "File was not opened." << std::endl;
	else
	{
		std::string str;
		while (!inFile.eof())
		{
			std::getline(inFile, str);
			try
			{
				CHttpUrl url(str);
				std::cout << url.GetURL() << std::endl;
			}
			catch (const std::exception& e)
			{
				std::cout << e.what() << std::endl;
			}
		}
	}

	return 0;
}
