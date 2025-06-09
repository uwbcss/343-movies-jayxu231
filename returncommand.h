#ifndef RETURNCOMMAND_H
#define RETURNCOMMAND_H

#include "command.h"

class ReturnCommand : public Command {
public:
    ReturnCommand();
    bool setData(const std::string& line) override;
    void execute(Store& store) override;
    Command* create() const override; 

private:
    int customerID;
    char mediaType;
    char genreCode;
    std::string movieData;
};

#endif
