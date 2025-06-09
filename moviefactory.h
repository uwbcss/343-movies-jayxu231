#ifndef MOVIEFACTORY_H
#define MOVIEFACTORY_H

#include <map>
#include "movie.h"

class MovieFactory {
public:

    static Movie* createMovie(char code);


    static bool registerGenre(char code, Movie* prototype);

private:
    static std::map<char, Movie*> registry;
};

#endif
