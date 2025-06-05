#include "borrow.h"

Borrow::Borrow() {}

void Borrow::display() const {
    std::cout << "Borrowed: ";
    if (movie) movie->display();
}

Transaction* Borrow::create() const {
    return new Borrow();
}

void Borrow::setData(Movie* m, int id) {
    movie = m;
    customerID = id;
}