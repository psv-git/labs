#include "functions.hpp"

// Выводит состояние двигателя автомобиля, направление движения, скорость и передачу
void Info(CCar& car)
{
	std::cout << "Engine state: ";
	if (car.checkEngineOn())
	{
		std::cout << "on.";
	}
	else
	{
		std::cout << "off.";
	}
	std::cout << std::endl
			  << "Current direction: ";
	Direction dir = car.checkMoveDirection();
	if (dir == Direction::STOP)
	{
		std::cout << "stop.";
	}
	else if (dir == Direction::BACKWARD)
	{
		std::cout << "back.";
	}
	else
	{
		std::cout << "forward.";
	}
	std::cout << std::endl
			  << "Current speed: ";
	std::cout << car.checkSpeed() << ".";
	std::cout << std::endl
			  << "Current gear: ";
	std::cout << car.checkGear() << "." << std::endl;
}

// Включает двигатель
void EngineOn(CCar& car)
{
	car.turnOnEngine();
}

// Выключает двигатель
void EngineOff(CCar& car)
{
	car.turnOffEngine();
}

// Включает заданную передачу. В случае ошибки сообщает о невозможности переключения передачи
void SetGear(CCar& car, int gear)
{
	if (!car.setGear(gear))
	{
		std::cout << "Gear " << gear << " can not be set." << std::endl;
	}
}

// Устанавливает указанную скорость движения. В случае невозможности изменения скорости сообщает о невозможности изменить скорость на указанную
void SetSpeed(CCar& car, int speed)
{
	if (!car.setSpeed(speed))
	{
		std::cout << "Speed " << speed << " can not be set." << std::endl;
	}
}

std::vector<std::string> ParseString(const std::string& str, char delim)
{
	std::vector<std::string> container;
	std::string subStr;
	for (char ch : str)
	{
		if (ch == delim)
		{
			if (!subStr.empty())
			{
				container.push_back(subStr);
				subStr.clear();
			}
		}
		else if (ch != '\0' && ch != '\n' && ch != '\r')
		{
			subStr.push_back(ch);
		}
		else
			break;
	}
	if (!subStr.empty())
		container.push_back(subStr);
	return container;
}

int StrToInt(const std::string& str, bool& err)
{
	err = false;
	int number = 0;
	size_t pos;
	try
	{
		number = std::stoi(str, &pos, 10);
		if (pos != str.size())
			err = true;
	}
	catch (...)
	{
		err = true;
	}
	return number;
}
