#ifndef _DELAYEDTYPER_H_
#define _DELAYEDTYPER_H_

#include <memory>
#include "CommandEngine.h"
#include "Command.h"
#include "SleepCommand.h"

class DelayedTyper : public Command 
{
    public:
        DelayedTyper(long delay, char c, CommandEngine &engine)
            : delay(delay), c(c), engine(engine), stop(false), sleepCommand(nullptr) {};

        void run() override;
    private:
        void delayAndRepeat();

        long delay;
        char c;
        CommandEngine &engine;
        bool stop;
        std::shared_ptr<SleepCommand> sleepCommand;
};

#endif
