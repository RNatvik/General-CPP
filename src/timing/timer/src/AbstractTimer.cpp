#include "timer/AbstractTimer.h"

AbstractTimer::AbstractTimer(unsigned long timeout) {
    _clk = RunClock();
    _timeout = timeout;
}

void AbstractTimer::initialize() {
    _clk.begin();
}
void AbstractTimer::setTimeout(unsigned long timeout) {
    _timeout = timeout;
}
bool AbstractTimer::check(bool reset) {
    unsigned long dt = getDuration();
    bool timeout = dt >= _timeout;
    if (timeout && reset) {
        _clk.begin();
    }
    return timeout;
}