#include "CCar.hpp"

std::map<Gear, std::pair<int, int>> gearSpeedRange = {
	{ Gear::BACK, std::pair<int, int>(0, 20) },
	{ Gear::NEUTRAL, std::pair<int, int>(0, 150) },
	{ Gear::ONE, std::pair<int, int>(0, 30) },
	{ Gear::TWO, std::pair<int, int>(20, 50) },
	{ Gear::THREE, std::pair<int, int>(30, 60) },
	{ Gear::FOUR, std::pair<int, int>(40, 90) },
	{ Gear::FIVE, std::pair<int, int>(50, 150) }
};

CCar::CCar()
{
	isEngineOn = false;
	currDirection = Direction::STOP;
	currSpeed = 0;
	currGear = Gear::NEUTRAL;
}

CCar::~CCar() {}

bool CCar::turnOnEngine()
{
	if (!isEngineOn)
	{
		isEngineOn = true;
		return true;
	}
	return false;
}

bool CCar::turnOffEngine()
{
	if (isEngineOn && currGear == Gear::NEUTRAL && currSpeed == 0)
	{
		isEngineOn = false;
		return true;
	}
	return false;
}

bool CCar::setGear(int gear)
{
	bool isSuccess = false;
	Gear g = intToGear(gear);
	if (g == Gear::NEUTRAL)
	{
		isSuccess = true;
	}
	if (isEngineOn && !isSuccess)
	{
		if (g == Gear::BACK)
		{
			if (currDirection != Direction::FORWARD)
			{
				isSuccess = true;
			}
		}
		else if (g != Gear::NONE)
		{
			if (currDirection != Direction::BACKWARD)
			{
				if (checkChangeGearOnSuccess(g))
				{
					isSuccess = true;
				}
			}
		}
	}
	if (isSuccess)
	{
		changeGear(g);
		return true;
	}
	return false;
}

bool CCar::setSpeed(int speed)
{
	bool isSuccess = false;
	if (isEngineOn)
	{
		if (currGear != Gear::NEUTRAL)
		{
			if (checkChangeSpeedOnSuccess(speed))
			{
				isSuccess = true;
			}
		}
		else if (speed == 0)
		{
			isSuccess = true;
		}
	}
	if (isSuccess)
	{
		changeSpeed(speed);
		return true;
	}
	return false;
}

// ============================================================================

bool CCar::checkEngineOn() const
{
	return isEngineOn;
}

Direction CCar::checkMoveDirection() const
{
	return currDirection;
}

int CCar::checkSpeed() const
{
	return currSpeed;
}

int CCar::checkGear() const
{
	return gearToInt(currGear);
}

// ============================================================================

bool CCar::checkChangeSpeedOnSuccess(int speed) const
{
	return (speed >= gearSpeedRange[currGear].first && speed <= gearSpeedRange[currGear].second);
}

bool CCar::checkChangeGearOnSuccess(Gear gear) const
{
	return (currSpeed >= gearSpeedRange[gear].first && currSpeed <= gearSpeedRange[gear].second);
}

void CCar::changeSpeed(int speed)
{
	currSpeed = speed;
	if (speed == 0)
	{
		changeDirection(Direction::STOP);
	}
	else if (currGear == Gear::BACK)
	{
		changeDirection(Direction::BACKWARD);
	}
	else
	{
		changeDirection(Direction::FORWARD);
	}
}

void CCar::changeGear(Gear gear)
{
	currGear = gear;
}

void CCar::changeDirection(Direction direction)
{
	currDirection = direction;
}

Gear CCar::intToGear(int gear) const
{
	switch (gear)
	{
	case -1:
		return Gear::BACK;
	case 0:
		return Gear::NEUTRAL;
	case 1:
		return Gear::ONE;
	case 2:
		return Gear::TWO;
	case 3:
		return Gear::THREE;
	case 4:
		return Gear::FOUR;
	case 5:
		return Gear::FIVE;
	default:
		return Gear::NONE;
	}
}

int CCar::gearToInt(Gear gear) const
{
	switch (gear)
	{
	case Gear::BACK:
		return -1;
	case Gear::NEUTRAL:
		return 0;
	case Gear::ONE:
		return 1;
	case Gear::TWO:
		return 2;
	case Gear::THREE:
		return 3;
	case Gear::FOUR:
		return 4;
	case Gear::FIVE:
		return 5;
	default:
		return -100;
	}
}
