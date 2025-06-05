#include "customer.h"
#include <iostream>

Customer::Customer(int id, const std::string& first, const std::string& last)
    : id(id), firstName(first), lastName(last) {}

int Customer::getID() const {
    return id;
}

std::string Customer::getFullName() const {
    return firstName + " " + lastName;
}

void Customer::addTransaction(Transaction* t) {
    history.push_back(t);
}

void Customer::displayHistory() const {
    std::cout << "Transaction history for " << getFullName()
              << " (ID: " << id << "):\n";
    for (const auto& t : history) {
        t->display();
    }
}
