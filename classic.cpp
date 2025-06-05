#include "classic.h"
#include <sstream>
#include <iomanip>

bool Classic::setData(std::istream& in) {
    in >> stock;
    in.ignore(); // skip comma
    getline(in, director, ',');
    director = director.substr(1);
    getline(in, title, ',');
    title = title.substr(1);
    in >> majorActorFirst >> majorActorLast >> month >> year;
    return !director.empty() && !title.empty() && month > 0 && year > 0;
}

std::string Classic::getKey() const {
    return std::to_string(month) + std::to_string(year) + "_" +
           majorActorFirst + "_" + majorActorLast;
}

void Classic::display() const {
    std::cout << std::setw(30) << title << " | "
              << month << "/" << year << " | "
              << majorActorFirst << " " << majorActorLast
              << " (Stock: " << stock << ")\n";
}

Movie* Classic::create() const {
    return new Classic();
}

bool Classic::operator<(const Movie& other) const {
    const Classic* c = dynamic_cast<const Classic*>(&other);
    if (!c) return false;
    if (year != c->year)
        return year < c->year;
    if (month != c->month)
        return month < c->month;
    std::string thisActor = majorActorFirst + " " + majorActorLast;
    std::string otherActor = c->majorActorFirst + " " + c->majorActorLast;
    return thisActor < otherActor;
}
