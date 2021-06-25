#include "stdafx.h"
#include "../libs/functions.hpp"

int main(int argc, char* argv[])
{
	CCar car;
	std::string inputString;
	std::vector<std::string> command;
	while (true)
	{
		command.clear();
		std::cout << ">";
		std::getline(std::cin, inputString);
		command = ParseString(inputString, ' ');
		if (command.size() == 0)
		{
			std::cout << "Available comands: ";
			std::cout << "\"Exit\" "
					  << "\"Info\" "
					  << "\"EngineOn\" "
					  << "\"EngineOff\" "
					  << "\"SetGear <-1..5>\" "
					  << "\"SetSpeed <0..150>\"" << std::endl;
			continue;
		}
		if (command[0] == "Exit")
		{
			break;
		}
		if (command[0] == "Info")
		{
			Info(car);
		}
		if (command[0] == "EngineOn")
		{
			EngineOn(car);
		}
		if (command[0] == "EngineOff")
		{
			EngineOff(car);
		}
		if (command.size() == 2)
		{
			bool error;
			if (command[0] == "SetGear")
			{
				int gear = StrToInt(command[1], error);
				if (!error)
				{
					SetGear(car, gear);
				}
			}
			if (command[0] == "SetSpeed")
			{
				int speed = StrToInt(command[1], error);
				if (!error)
				{
					SetSpeed(car, speed);
				}
			}
		}
	}

	return 0;
}
