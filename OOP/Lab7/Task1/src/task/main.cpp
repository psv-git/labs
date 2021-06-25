#include "stdafx.h"
#include "../libs/Functions.hpp"
#include "../libs/Sportsmen.hpp"

struct SportsmenDescription
{
	std::string fullName;
	double height;
	double weight;
} III = { "Ivanov Ivan Ivanovich", 1.2, 65 },
  PPP = { "Petrov Petr Petrovich", 1, 56 },
  SSS = { "Sidorov Sidor Sidorovich", 1.9, 47 },
  EEE = { "Egorov Egor Egorovich", 2.5, 39 },
  UDD = { "", 2, 80 },
  DUD = { "Artemov Artem Artemovich", 0, 24 },
  DDU = { "Maksimov Maksim Maksimovich", 2.1, 0 },
  FFF = { "Filonov Filon Filonovich", 1.7, 89 };

std::vector<SportsmenDescription> sportsmensDescriptionList = {
	III, PPP, SSS, EEE, UDD, DUD, DDU, FFF
};

std::vector<Sportsmen*> sportsmensList;
Sportsmen* sportsmen = nullptr;

// ============================================================================

int main(int argc, char* argv[])
{
	// fill sportsmens list
	for (const auto& sD : sportsmensDescriptionList)
	{
		try
		{
			Sportsmen* sObj = new Sportsmen(sD.fullName, sD.height, sD.weight);
			sportsmensList.push_back(sObj);
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	// get sportsmen with max height
	if (!FindMaxEx(sportsmensList, sportsmen, LessByHeight<Sportsmen*>))
	{
		std::cout << "Sportsmens list is empty." << std::endl;
	}
	if (sportsmen)
	{
		std::cout << "Sportsmen with max height: " << sportsmen->GetFullName() << " has height " << sportsmen->GetHeight() << std::endl;
	}
	else
	{
		std::cout << "Error: something went wrong." << std::endl;
	}

	// get sportsmen with max weight
	sportsmen = nullptr;
	if (!FindMaxEx(sportsmensList, sportsmen, LessByWeight<Sportsmen*>))
	{
		std::cout << "Sportsmens list is empty." << std::endl;
	}
	if (sportsmen)
	{
		std::cout << "Sportsmen with max weight: " << sportsmen->GetFullName() << " has weight " << sportsmen->GetWeight() << std::endl;
	}
	else
	{
		std::cout << "Error: something went wrong." << std::endl;
	}

	// delete sportsmens
	for (const auto& sObj : sportsmensList)
	{
		delete sObj;
	}

	return 0;
}
