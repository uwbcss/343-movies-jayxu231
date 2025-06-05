#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>
#include "movie.h"

class Transaction {
public:
    virtual ~Transaction() {}
    virtual void display() const = 0;
    virtual Transaction* create() const = 0;
    virtual void setData(Movie* movie, int customerID) = 0;

protected:
    Movie* movie = nullptr;
    int customerID = -1;
};

#endif
