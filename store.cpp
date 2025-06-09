#include "store.h"
#include "moviefactory.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include "commandfactory.h"

Store::Store() {}

Store::~Store() {
    for (Movie* m : comedyInventory) delete m;
    for (Movie* m : dramaInventory) delete m;
    for (Movie* m : classicInventory) delete m;
}

void Store::loadCustomers(const std::string& filename) {
    std::ifstream file(filename);
    int id;
    std::string last, first;
    while (file >> id >> last >> first) {
        Customer* cust = new Customer(id, first, last);
        customers.insert(id, cust);
    }
}

void Store::loadMovies(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    while (getline(file, line)) {
        if (line.empty()) continue;
        std::istringstream ss(line);
        char genreCode;
        ss >> genreCode;
        ss.ignore();

        Movie* movie = MovieFactory::createMovie(genreCode);
        if (!movie) {
            std::cerr << "Invalid movie genre: " << genreCode << std::endl;
            continue;
        }

        if (!movie->setData(ss)) {
            std::cerr << "Invalid movie data: " << line << std::endl;
            delete movie;
            continue;
        }

        auto& inventory = getInventoryForGenre(genreCode);
        inventory.push_back(movie);
    }

    std::sort(comedyInventory.begin(), comedyInventory.end());
    std::sort(dramaInventory.begin(), dramaInventory.end());
    std::sort(classicInventory.begin(), classicInventory.end());
}

std::vector<Movie*>& Store::getInventoryForGenre(char genre) {
    switch (genre) {
        case 'F': return comedyInventory;
        case 'D': return dramaInventory;
        case 'C': return classicInventory;
        default:
            throw std::runtime_error("Invalid genre access in store");
    }
}

void Store::displayInventory() const {
    std::cout << "Comedy Inventory:\n";
    for (Movie* m : comedyInventory) m->display();

    std::cout << "\nDrama Inventory:\n";
    for (Movie* m : dramaInventory) m->display();

    std::cout << "\nClassic Inventory:\n";
    for (Movie* m : classicInventory) m->display();
}

void Store::displayCustomerHistory(int customerID) const {
    Customer* c = customers.retrieve(customerID);
    if (!c) {
        std::cerr << "Customer ID not found: " << customerID << std::endl;
        return;
    }
    c->displayHistory();
}

void Store::processCommands(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    while (getline(file, line)) {
        std::istringstream ss(line);
        char commandCode;
        ss >> commandCode;
        Command* cmd = CommandFactory::createCommand(commandCode);
        if (!cmd) {
            std::cerr << "Invalid command code: " << commandCode << std::endl;
            continue;
        }

        std::string restOfLine;
        getline(ss, restOfLine);
        if (cmd->setData(restOfLine)) {
            cmd->execute(*this);
        } else {
            std::cerr << "Failed to parse command line: " << line << std::endl;
        }
        delete cmd;
    }
}
Customer* Store::getCustomer(int customerID) const {
    return customers.retrieve(customerID);
}

Movie* Store::findMovie(const Movie* target, char genreCode) const {
    const std::vector<Movie*>* inventory = nullptr;
    switch (genreCode) {
        case 'F': inventory = &comedyInventory; break;
        case 'D': inventory = &dramaInventory; break;
        case 'C': inventory = &classicInventory; break;
        default: return nullptr;
    }

    for (Movie* m : *inventory) {
        if (m->getKey() == target->getKey()) {
            return m;
        }
    }
    return nullptr;
}
