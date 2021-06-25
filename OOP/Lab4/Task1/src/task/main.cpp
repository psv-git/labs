#include "stdafx.h"
#include "../libs/CBodiesController.hpp"

int main(int argc, char* argv[])
{
	CBodiesController controller;
	controller.ReadBodiesFromIstream(std::cin);
	controller.PrintBodies();
	controller.PrintBodyWithMaxMass();
	controller.PrintBodyWithMinWeightInWater();

	return 0;
}
