#include "timer/MillisTimer.h"
#include <iostream>

int main()
{
    MillisTimer mt = MillisTimer(1000);
    mt.initialize();
    std::cout << "Hello: " << mt.getDuration() << std::endl;
    while (!mt.check(true));
    std::cout << "Bye: " << mt.getDuration() << std::endl;
    return 0;
}