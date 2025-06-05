#ifndef COMEDY_H
#define COMEDY_H

#include "movie.h"

class Comedy : public Movie {
public:
    bool setData(std::istream& in) override;
    std::string getKey() const override;
    void display() const override;
    Movie* create() const override;
    bool operator<(const Movie& other) const override;
};

#endif
