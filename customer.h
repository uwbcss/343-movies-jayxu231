#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>
#include "transaction.h"

class Customer {
public:
    Customer(int id, const std::string& firstName, const std::string& lastName);
    int getID() const;
    std::string getFullName() const;
    void addTransaction(Transaction* t);
    void displayHistory() const;

private:
    int id;
    std::string firstName, lastName;
    std::vector<Transaction*> history;
};

#endif