#include <iostream>
#include "HashTable.h"

using namespace std;

const int C_TABLE_SIZE = 64;

HashRecord::HashRecord(int key, int value) {
    this->key = key;
    this->value = value;
}

HashTable::HashTable(int (*hashFunc)(int)) {
    hashFunction = hashFunc;
    hash_table = new HashRecord * [C_TABLE_SIZE];
    for (int i = 0; i < C_TABLE_SIZE; i++) {
        hash_table[i] = NULL;
    }
}

HashTable::~HashTable() {
    for (int i = 0; i < C_TABLE_SIZE; i++) {
        if (hash_table[i] != NULL) {
            delete hash_table[i];
        }
    }
    if (hash_table != NULL) {
        delete[] hash_table;
    }
    cout << "Bye, leaving the application..." << endl;
}

int HashTable::hashFunction1(int key) {
    return key % C_TABLE_SIZE;
}

int HashTable::hashFunction2(int key) {
    return (key / C_TABLE_SIZE) % C_TABLE_SIZE;
}

void HashTable::insertRecord(int key, int value) {
    int hash = hashFunction(key);
    int startHash = hash;
    while (hash_table[hash] != NULL && hash_table[hash]->key != key) {
        hash = hashFunction(hash + 1);
        if (hash == startHash) {
            cout << "Hash table is full!" << endl;
            return;
        }
    }
    if (hash_table[hash] != NULL) {
        delete hash_table[hash];
    }
    hash_table[hash] = new HashRecord(key, value);
}

int HashTable::findRecord(int key) {
    int hash = hashFunction(key);
    int startHash = hash;
    while (hash_table[hash] != NULL && hash_table[hash]->key != key) {
        hash = hashFunction(hash + 1);
        if (hash == startHash) {
            return -1;
        }
    }
    if (hash_table[hash] == NULL) {
        return -1;
    }
    return hash_table[hash]->value;
}

void HashTable::deleteRecord(int key) {
    int hash = hashFunction(key);
    int startHash = hash;
    while (hash_table[hash] != NULL) {
        if (hash_table[hash]->key == key) {
            delete hash_table[hash];
            hash_table[hash] = NULL;
            cout << "Element with the key " << key << " found and deleted" << endl;
            return;
        }
        hash = hashFunction(hash + 1);
        if (hash == startHash) {
            break;
        }
    }
    cout << "No element found with the given key " << key << endl;
}

void HashTable::printTable() {
    for (int i = 0; i < C_TABLE_SIZE; i++) {
        if (hash_table[i] != NULL) {
            cout << "Key: " << hash_table[i]->key << ", Value: " << hash_table[i]->value << endl;
        }
    }
}
