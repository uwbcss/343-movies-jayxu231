#include "hashtable.h"

HashTable::HashTable() : table(TABLE_SIZE, nullptr) {}

HashTable::~HashTable() {
    for (Node* head : table) {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp->customer; 
            delete temp;
        }
    }
}

int HashTable::hash(int id) const {
    return id % TABLE_SIZE;
}

void HashTable::insert(int id, Customer* customer) {
    int idx = hash(id);
    Node* node = new Node(id, customer);
    node->next = table[idx];
    table[idx] = node;
}

Customer* HashTable::retrieve(int id) const {
    int idx = hash(id);
    Node* current = table[idx];
    while (current) {
        if (current->id == id) return current->customer;
        current = current->next;
    }
    return nullptr;
}
