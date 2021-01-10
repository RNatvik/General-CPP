#ifndef MillisTimer_h
#define MillisTimer_h

#include "timer/AbstractTimer.h"

class MillisTimer: public AbstractTimer {

    public:
    MillisTimer(unsigned long timeout);
    unsigned long getDuration() override;
};

#endif