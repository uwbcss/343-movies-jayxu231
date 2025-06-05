#ifndef BORROW_H
#define BORROW_H

#include "transaction.h"

class Borrow : public Transaction {
public:
    Borrow();
    void display() const override;
    Transaction* create() const override;
    void setData(Movie* movie, int customerID) override;
};

#endif