#ifndef HISTORYCOMMAND_H
#define HISTORYCOMMAND_H

#include "command.h"
#include <sstream>

class HistoryCommand : public Command {
public:
    HistoryCommand() : customerID(-1) {}
    bool setData(const std::string& line) override {
        std::istringstream ss(line);
        ss >> customerID;
        return customerID >= 0;
    }
    void execute(Store& store) override {
        store.displayCustomerHistory(customerID);
    }
    Command* create() const override { return new HistoryCommand(); }

private:
    int customerID;
};

#endif
