#include "CommandEngine.h"

void CommandEngine::addCommand(Command *command)
{
    commandList.push_back(command);
}

void CommandEngine::run() {
    while(!commandList.empty()) {
        Command *command = commandList.front();
        commandList.pop_front();
        command->run();
    }
}

