#ifndef AbstractTimerClass_h
#define AbstractTimerClass_h

#include "clock/RunClock.h"

class AbstractTimer {
    protected:
    RunClock _clk;
    unsigned long _timeout;

    public:
    AbstractTimer(unsigned long timeout);
    void initialize();
    void setTimeout(unsigned long timeout);
    bool check(bool reset);
    virtual unsigned long getDuration() = 0;
};


#endif