#ifndef RETURN_H
#define RETURN_H

#include "transaction.h"

class Return : public Transaction {
public:
    Return();
    void display() const override;
    Transaction* create() const override; 
    void setData(Movie* movie, int customerID) override;
};

#endif
