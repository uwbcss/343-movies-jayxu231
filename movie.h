#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <iostream>

class Movie {
public:
    virtual ~Movie() {}
    virtual bool setData(std::istream& in) = 0;
    virtual std::string getKey() const = 0;
    virtual void display() const = 0;
    virtual Movie* create() const = 0;
    virtual bool operator<(const Movie& other) const = 0;

    void increaseStock() { ++stock; }
    void decreaseStock() { if (stock > 0) --stock; }
    int getStock() const { return stock; }

protected:
    int stock = 0;
    std::string director;
    std::string title;
    int year = 0;
};

#endif