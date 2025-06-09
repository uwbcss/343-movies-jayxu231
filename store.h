#ifndef STORE_H
#define STORE_H

#include <vector>
#include <string>
#include <map>
#include "movie.h"
#include "customer.h"
#include "hashtable.h"

class Store {
public:
    Store();
    ~Store();

    void loadCustomers(const std::string& filename);
    void loadMovies(const std::string& filename);
    void processCommands(const std::string& filename);
    void displayInventory() const;
    void displayCustomerHistory(int customerID) const;

private:
    HashTable customers;

    // Inventories by genre code
    std::vector<Movie*> comedyInventory;
    std::vector<Movie*> dramaInventory;
    std::vector<Movie*> classicInventory;

    std::vector<Movie*>& getInventoryForGenre(char genre);
};

#endif
