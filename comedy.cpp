#include "comedy.h"
#include <sstream>
#include <iomanip>

bool Comedy::setData(std::istream& in) {
    in >> stock;
    in.ignore(); 
    getline(in, director, ',');
    director = director.substr(1);
    getline(in, title, ',');
    title = title.substr(1); 
    in >> year;
    return !director.empty() && !title.empty() && year > 0;
}

std::string Comedy::getKey() const {
    return title + std::to_string(year);
}

void Comedy::display() const {
    std::cout << std::setw(30) << std::left << title
              << " " << year << " (Stock: " << stock << ")\n";
}

Movie* Comedy::create() const {
    return new Comedy();
}

bool Comedy::operator<(const Movie& other) const {
    const Comedy* c = dynamic_cast<const Comedy*>(&other);
    if (!c) return false;
    if (title != c->title)
        return title < c->title;
    return year < c->year;
}
