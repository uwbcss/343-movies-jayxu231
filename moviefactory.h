#ifndef MOVIEFACTORY_H
#define MOVIEFACTORY_H

#include <map>
#include "movie.h"

class MovieFactory {
public:
    // Create a Movie* based on genre code, e.g., 'F', 'D', 'C'
    static Movie* createMovie(char code);

    // Register a prototype to a genre code
    static bool registerGenre(char code, Movie* prototype);

private:
    static std::map<char, Movie*> registry;
};

#endif
