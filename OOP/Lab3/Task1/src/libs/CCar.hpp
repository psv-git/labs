#ifndef CCAR_HPP
#define CCAR_HPP

#include "../task/stdafx.h"

class CCar
{

public:
	CCar();
	~CCar();

	bool turnOnEngine(); // Включает двигатель
	bool turnOffEngine(); // Выключает двигатель
	bool setGear(int gear); // Включает заданную передачу
	bool setSpeed(int speed); // Устанавливает указанную скорость движения

	bool checkEngineOn() const;
	Direction checkMoveDirection() const;
	int checkSpeed() const;
	int checkGear() const;

private:
	bool isEngineOn;
	Direction currDirection;
	int currSpeed;
	Gear currGear;

	bool checkChangeSpeedOnSuccess(int speed) const;
	bool checkChangeGearOnSuccess(Gear gear) const;
	void changeSpeed(int speed);
	void changeGear(Gear gear);
	void changeDirection(Direction direction);
	Gear intToGear(int gear) const;
	int gearToInt(Gear gear) const;
};

#endif // CCAR_HPP