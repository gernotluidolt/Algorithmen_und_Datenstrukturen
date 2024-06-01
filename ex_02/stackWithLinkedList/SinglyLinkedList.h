#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include <iostream>

class SinglyLinkedList {
private:
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };

    Node* head;
    int size;

public:
    SinglyLinkedList();
    ~SinglyLinkedList();

    bool isEmpty() const;
    int getSize() const;
    void insertAtFirst(int data);
    void insertAtLast(int data);
    void insertAt(int index, int data);
    bool remove(int data);
    bool search(int data) const;
    void printList() const;
    void removeLastNode();
    void removeFirstNode();
    void removeNodeAt(int index);


};

#endif // SINGLYLINKEDLIST_H
