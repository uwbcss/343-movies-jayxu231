#include "inventorycommand.h"
#include "commandfactory.h"

namespace {
    struct RegisterInventory {
        RegisterInventory() {
            CommandFactory::registerCommand('I', new InventoryCommand());
        }
    };
    static RegisterInventory registerInventory;
}
