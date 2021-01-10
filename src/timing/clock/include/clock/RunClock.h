#ifndef RunClock_h
#define RunClock_h
#include <chrono>

class RunClock {
    private:
    std::chrono::_V2::system_clock::time_point _t0;

    public:
    RunClock();

    void begin();
    unsigned long millis();   
    unsigned long micros();
    unsigned long seconds();
};


#endif