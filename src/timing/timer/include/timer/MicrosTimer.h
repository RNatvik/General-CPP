#ifndef MicrosTimer_h
#define MicrosTimer_h

#include "timer/AbstractTimer.h"

class MicrosTimer: public AbstractTimer {

    public:
    MicrosTimer(unsigned long timeout);
    unsigned long getDuration() override;
};

#endif