#include "timer/MillisTimer.h"

MillisTimer::MillisTimer(unsigned long timeout) : AbstractTimer(timeout) {}

unsigned long MillisTimer::getDuration() {
    return _clk.millis();
}