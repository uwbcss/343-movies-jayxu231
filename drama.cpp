#include "drama.h"
#include <sstream>
#include <iomanip>

bool Drama::setData(std::istream& in) {
    in >> stock;
    in.ignore(); 
    getline(in, director, ',');
    director = director.substr(1);
    getline(in, title, ',');
    title = title.substr(1);
    in >> year;
    return !director.empty() && !title.empty() && year > 0;
}

std::string Drama::getKey() const {
    return director + "_" + title;
}

void Drama::display() const {
    std::cout << std::setw(25) << std::left << director << " | "
              << std::setw(30) << title
              << " (" << year << ", Stock: " << stock << ")\n";
}

Movie* Drama::create() const {
    return new Drama();
}

bool Drama::operator<(const Movie& other) const {
    const Drama* d = dynamic_cast<const Drama*>(&other);
    if (!d) return false;
    if (director != d->director)
        return director < d->director;
    return title < d->title;
}
