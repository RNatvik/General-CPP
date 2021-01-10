#include "timer/MicrosTimer.h"

MicrosTimer::MicrosTimer(unsigned long timeout) : AbstractTimer(timeout) {}

unsigned long MicrosTimer::getDuration() {
    return _clk.micros();
}