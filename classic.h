#ifndef CLASSIC_H
#define CLASSIC_H

#include "movie.h"

class Classic : public Movie {
public:
    bool setData(std::istream& in) override;
    std::string getKey() const override;
    void display() const override;
    Movie* create() const override;
    bool operator<(const Movie& other) const override;

private:
    std::string majorActorFirst;
    std::string majorActorLast;
    int month = 0;
};

#endif
