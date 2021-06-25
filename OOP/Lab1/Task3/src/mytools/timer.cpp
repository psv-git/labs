#include "timer.hpp"

using namespace Mts;

Timer::Timer()
{
	startTime = 0;
	finishTime = 0;
}

Timer::~Timer() {}

void Timer::startTimer()
{
	startTime = std::clock();
}

void Timer::stopTimer()
{
	finishTime = std::clock();
}

float Timer::getTime()
{
	return (float)(finishTime - startTime) / CLOCKS_PER_SEC;
}
