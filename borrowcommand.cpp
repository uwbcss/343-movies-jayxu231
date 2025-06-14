#include "borrowcommand.h"
#include "borrow.h"
#include "moviefactory.h"
#include "commandfactory.h"
#include <sstream>
#include <iostream>

namespace {
    struct RegisterBorrow {
        RegisterBorrow() {
            CommandFactory::registerCommand('B', new BorrowCommand());
        }
    };
    static RegisterBorrow registerBorrow;
}


BorrowCommand::BorrowCommand() {}

bool BorrowCommand::setData(const std::string& line) {
    std::istringstream ss(line);
    ss >> customerID >> mediaType >> genreCode;
    getline(ss, movieData);
    return true;
}

void BorrowCommand::execute(Store& store) {
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
        std::cerr << "Bad movie data in borrow command\n";
        delete temp;
        return;
    }

    Movie* actual = store.findMovie(temp, genreCode);
    delete temp;
    if (!actual) {
        std::cerr << "Movie not found\n";
        return;
    }

    if (actual->getStock() == 0) {
        std::cerr << "Out of stock\n";
        return;
    }

    actual->decreaseStock();
    Borrow* t = new Borrow();
    t->setData(actual, customerID);
    cust->addTransaction(t);
}

Command* BorrowCommand::create() const {
    return new BorrowCommand();
}
