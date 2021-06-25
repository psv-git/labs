#include "timer.hpp"

using namespace Mts;

Timer::Timer() {}

Timer::~Timer() {}

void Timer::startTimer()
{
	startTime = std::chrono::steady_clock::now();
}

void Timer::stopTimer()
{
	finishTime = std::chrono::steady_clock::now();
}

float Timer::getTime()
{
	return std::chrono::duration<double>(finishTime - startTime).count();
}

void Timer::pause(int second)
{
	std::chrono::seconds dur{ second };
	std::this_thread::sleep_for(dur);
}
