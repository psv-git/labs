#ifndef TIMER_HPP
#define TIMER_HPP

#include <ctime>

namespace Mts
{

class Timer
{

public:
	Timer();
	~Timer();

	void startTimer();
	void stopTimer();
	float getTime();

private:
	time_t startTime;
	time_t finishTime;
};
}

#endif // TIMER_HPP
