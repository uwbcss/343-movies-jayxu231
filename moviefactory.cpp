#include "moviefactory.h"
#include "comedy.h"
#include "drama.h"
#include "classic.h"

std::map<char, Movie*> MovieFactory::registry;

Movie* MovieFactory::createMovie(char code) {
    if (registry.find(code) != registry.end()) {
        return registry[code]->create();  
    }
    return nullptr;
}

bool MovieFactory::registerGenre(char code, Movie* prototype) {
    if (registry.find(code) != registry.end()) return false;
    registry[code] = prototype;
    return true;
}

// Static initialization
namespace {
    const bool registeredComedy = MovieFactory::registerGenre('F', new Comedy());
    const bool registeredDrama = MovieFactory::registerGenre('D', new Drama());
    const bool registeredClassic = MovieFactory::registerGenre('C', new Classic());
}
