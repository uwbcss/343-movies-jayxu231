#ifndef INVENTORYCOMMAND_H
#define INVENTORYCOMMAND_H

#include "command.h"

class InventoryCommand : public Command {
public:
    InventoryCommand() {}
    bool setData(const std::string& line) override { return true; }
    void execute(Store& store) override {
        store.displayInventory();
    }
    Command* create() const override { return new InventoryCommand(); }
};

#endif
