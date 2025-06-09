#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include "store.h"

class Command {
public:
    virtual ~Command() {}
    virtual bool setData(const std::string& line) = 0;
    virtual void execute(Store& store) = 0;
    virtual Command* create() const = 0;
};

#endif
