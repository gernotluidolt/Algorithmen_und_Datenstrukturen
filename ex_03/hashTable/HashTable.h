#ifndef HASHTABLE_H
#define HASHTABLE_H

class HashRecord {
public:
    int key;
    int value;
    HashRecord(int key, int value);
};

class HashTable {
private:
    HashRecord** hash_table;
    int (*hashFunction)(int key); // Pointer to hash function

public:
    HashTable(int (*hashFunc)(int));
    ~HashTable();
    static int hashFunction1(int key);
    static int hashFunction2(int key);
    void insertRecord(int key, int value);
    int findRecord(int key);
    void deleteRecord(int key);
    void printTable();
};

#endif // HASHTABLE_H
