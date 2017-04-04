#ifndef _COMMAND_H_
#define _COMMAND_H_

class Command {
    public:
        virtual void run() = 0;
        virtual ~Command() = 0;
};

inline Command::~Command(){};

#endif
