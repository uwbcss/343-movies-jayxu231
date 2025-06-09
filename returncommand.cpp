#include "returncommand.h"
#include "return.h"
#include "moviefactory.h"
#include "commandfactory.h"
#include <sstream>
#include <iostream>

namespace {
    struct RegisterReturn {
        RegisterReturn() {
            CommandFactory::registerCommand('R', new ReturnCommand());
        }
    };
    static RegisterReturn registerReturn;
}


ReturnCommand::ReturnCommand() {}

bool ReturnCommand::setData(const std::string& line) {
    std::istringstream ss(line);
    ss >> customerID >> mediaType >> genreCode;
    getline(ss, movieData);
    return true;
}

void ReturnCommand::execute(Store& store) {
    Customer* cust = store.getCustomer(customerID);
    if (!cust) {
        std::cerr << "Invalid customer ID: " << customerID << std::endl;
        return;
    }

    Movie* temp = MovieFactory::createMovie(genreCode);
    if (!temp) {
        std::cerr << "Invalid movie genre: " << genreCode << std::endl;
        return;
    }

    std::istringstream ss(movieData);
    if (!temp->setData(ss)) {
        std::cerr << "Bad movie data in return command\n";
        delete temp;
        return;
    }

    Movie* actual = store.findMovie(temp, genreCode);
    delete temp;
    if (!actual) {
        std::cerr << "Movie not found\n";
        return;
    }

    actual->increaseStock();
    Return* t = new Return();
    t->setData(actual, customerID);
    cust->addTransaction(t);
}

Command* ReturnCommand::create() const {
    return new ReturnCommand();
}
