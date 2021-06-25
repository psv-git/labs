#include "stdafx.h"

int main(int argc, char* argv[])
{
	bool even = true;
	for (size_t i = 100; i > 0; i--)
	{
		if (even)
		{
			std::cout << i;
			if (i != 2)
			{
				std::cout << ", ";
			}
		}
		even = !even;
	}
	std::cout << std::endl;
	return 0;
}
