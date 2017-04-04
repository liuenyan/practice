#ifndef _SLEEP_COMMAND_H_
#define _SLEEP_COMMAND_H_

#include "CommandEngine.h"
#include "Command.h"

class SleepCommand : public Command
{
    public:
        SleepCommand(int milliseconds, CommandEngine &engine, 
                Command &wakeupCommand)
            : milliseconds(milliseconds), engine(engine), 
            wakeupCommand(wakeupCommand), start(false){};
        virtual ~SleepCommand() {};

        void run() override;
    private:
        long milliseconds;
        CommandEngine &engine;
        Command &wakeupCommand;
        bool start;
        long startTime;
};

#endif
