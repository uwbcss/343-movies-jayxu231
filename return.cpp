#include "return.h"

Return::Return() {}

void Return::display() const {
    std::cout << "Returned: ";
    if (movie) movie->display();
}

Transaction* Return::create() const {
    return new Return();
}

void Return::setData(Movie* m, int id) {
    movie = m;
    customerID = id;
}