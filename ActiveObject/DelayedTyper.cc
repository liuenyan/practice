#include <iostream>
#include "DelayedTyper.h"

void DelayedTyper::run()
{
    std::cout << c << std::endl;
    if(!stop) {
        delayAndRepeat();
    }
}

void DelayedTyper::delayAndRepeat()
{
    // delete last sleepCommand
    sleepCommand.reset(new SleepCommand(delay, engine, *this));
    // assume that engine willn't delete sleepCommand
    engine.addCommand(sleepCommand.get());
}

