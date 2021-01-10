#include "clock/RunClock.h"
#include <chrono>
#include <iostream>


RunClock::RunClock() {
    this->begin();
}

void RunClock::begin() {
    _t0 = std::chrono::high_resolution_clock::now();
}

unsigned long RunClock::millis() {
    std::chrono::_V2::system_clock::time_point t = std::chrono::high_resolution_clock::now();
    std::chrono::milliseconds duration = std::chrono::duration_cast<std::chrono::milliseconds>(t - _t0);

    return (unsigned long) duration.count();
}   
unsigned long RunClock::micros() {
    std::chrono::_V2::system_clock::time_point t = std::chrono::high_resolution_clock::now();
    std::chrono::microseconds duration = std::chrono::duration_cast<std::chrono::microseconds>(t - _t0);

    return (unsigned long) duration.count();
}
unsigned long RunClock::seconds() {
    std::chrono::_V2::system_clock::time_point t = std::chrono::high_resolution_clock::now();
    std::chrono::seconds duration = std::chrono::duration_cast<std::chrono::seconds>(t - _t0);

    return (unsigned long) duration.count();
}