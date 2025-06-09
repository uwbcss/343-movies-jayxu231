#ifndef BORROWCOMMAND_H
#define BORROWCOMMAND_H

#include "command.h"

class BorrowCommand : public Command {
public:
    BorrowCommand();
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
