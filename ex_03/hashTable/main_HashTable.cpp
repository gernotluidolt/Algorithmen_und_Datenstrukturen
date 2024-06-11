#include <iostream>
#include "HashTable.h"

using namespace std;

int main() {
    // 1. Create a hash table with the first hash function
    HashTable hashTable1(HashTable::hashFunction1);

    // 2. Insert 5 entries into the table
    hashTable1.insertRecord(10, 100);
    hashTable1.insertRecord(20, 200);
    hashTable1.insertRecord(30, 300);
    hashTable1.insertRecord(40, 400);
    hashTable1.insertRecord(50, 500);

    // 3. Print the table
    cout << "HashTable with Hash Function 1:" << endl;
    hashTable1.printTable();

    // 4. Create another hash table with the second hash function
    HashTable hashTable2(HashTable::hashFunction2);

    // 5. Insert 5 entries into the table
    hashTable2.insertRecord(10, 100);
    hashTable2.insertRecord(20, 200);
    hashTable2.insertRecord(30, 300);
    hashTable2.insertRecord(40, 400);
    hashTable2.insertRecord(50, 500);

    // 6. Print the table
    cout << "HashTable with Hash Function 2:" << endl;
