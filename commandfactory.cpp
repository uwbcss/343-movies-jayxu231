#include "commandfactory.h"

std::map<char, Command*> CommandFactory::registry;

Command* CommandFactory::createCommand(char code) {
    if (registry.find(code) != registry.end()) {
        return registry[code]->create(); // clone prototype
    }
    return nullptr;
}

bool CommandFactory::registerCommand(char code, Command* prototype) {
    if (registry.find(code) != registry.end()) return false;
    registry[code] = prototype;
    return true;
}
