#ifndef _COMMAND_ENGINE_H_
#define _COMMAND_ENGINE_H_

#include <list>
#include "Command.h"

class CommandEngine {
    public:
        void addCommand(Command *command);
        void run();
    private:
        std::list<Command*> commandList; 
};

#endif
