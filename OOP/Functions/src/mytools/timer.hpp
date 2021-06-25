#ifndef TIMER_HPP
#define TIMER_HPP


#include <chrono>
#include <thread>


namespace Mts {

  class Timer {

    public:

      Timer();
      ~Timer();

      void startTimer();
      void stopTimer();
      float getTime();
      void pause(int second);

    private:

      std::chrono::time_point<std::chrono::steady_clock> startTime;
      std::chrono::time_point<std::chrono::steady_clock> finishTime;

  };

}

#endif // TIMER_HPP
