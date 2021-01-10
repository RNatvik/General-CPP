#include <iostream>
#include "clock/RunClock.h"


int main() {
    RunClock clk = RunClock();
    clk.begin();
    std::cout << "Hello: " << clk.millis() << std::endl; 
    while (clk.millis() < 1000);
    
    std::cout << "Goodbye: " << clk.millis() << std::endl; 
    return 0;
}