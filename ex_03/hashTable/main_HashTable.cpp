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
    hashTable2.printTable();

    // 7. Search for a specific element in the table
    int keyToFind = 30;
    int valueFound = hashTable2.findRecord(keyToFind);
    if (valueFound != -1) {
        cout << "Element found with key " << keyToFind << ": Value = " << valueFound << endl;
    } else {
        cout << "Element with key " << keyToFind << " not found." << endl;
    }

    // 8. Delete an element in the table and print the table
    int keyToDelete = 20;
    hashTable2.deleteRecord(keyToDelete);
    cout << "HashTable with Hash Function 2 after deletion:" << endl;
    hashTable2.printTable();

    // 9. Delete another element in the table and print the table
    keyToDelete = 40;
    hashTable2.deleteRecord(keyToDelete);
    cout << "HashTable with Hash Function 2 after second deletion:" << endl;
    hashTable2.printTable();

    return 0;
}
