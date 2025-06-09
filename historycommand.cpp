#include "historycommand.h"
#include "commandfactory.h"

namespace {
    struct RegisterHistory {
        RegisterHistory() {
            CommandFactory::registerCommand('H', new HistoryCommand());
        }
    };
    static RegisterHistory registerHistory;
}
