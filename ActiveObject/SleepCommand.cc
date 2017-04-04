#include <iostream>
#include <ctime>
#include "SleepCommand.h"

inline static long currentMilliseconds() {
    struct timespec tp;
    clock_gettime(CLOCK_REALTIME, &tp);
    return tp.tv_sec * 1000 + tp.tv_nsec / 1000000;
}

void SleepCommand::run()
{
    long currentTime = currentMilliseconds();
    if(!start) {
        start = true;
        startTime = currentTime;
        engine.addCommand(this);
    } else if(currentTime - startTime < milliseconds) {
        engine.addCommand(this);
    } else {
        engine.addCommand(&wakeupCommand);
    }
}

