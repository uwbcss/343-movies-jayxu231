#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "customer.h"
#include <vector>

class HashTable {
public:
    HashTable();
    ~HashTable();

    void insert(int id, Customer* customer);
    Customer* retrieve(int id) const;

private:
    static const int TABLE_SIZE = 101; 

    struct Node {
        int id;
        Customer* customer;
        Node* next;
        Node(int i, Customer* c) : id(i), customer(c), next(nullptr) {}
    };

    std::vector<Node*> table;

    int hash(int id) const;
};

#endif
