#ifndef COMMANDFACTORY_H
#define COMMANDFACTORY_H

#include <map>
#include "command.h"

class CommandFactory {
public:
    static Command* createCommand(char code);
    static bool registerCommand(char code, Command* prototype);

private:
    static std::map<char, Command*> registry;
};

#endif
