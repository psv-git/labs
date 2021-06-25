#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include "../task/stdafx.h"
#include "CCar.hpp"

// Выводит состояние двигателя автомобиля, направление движения, скорость и передачу
void Info(CCar& car);
// Включает двигатель
void EngineOn(CCar& car);
// Выключает двигатель
void EngineOff(CCar& car);
// Включает заданную передачу. В случае ошибки сообщает о невозможности переключения передачи
void SetGear(CCar& car, int gear);
// Устанавливает указанную скорость движения. В случае невозможности изменения скорости сообщает о невозможности изменить скорость на указанную.
void SetSpeed(CCar& car, int speed);

std::vector<std::string> ParseString(const std::string& str, char delim);
int StrToInt(const std::string& str, bool& err);

#endif // FUNCTIONS_HPP
