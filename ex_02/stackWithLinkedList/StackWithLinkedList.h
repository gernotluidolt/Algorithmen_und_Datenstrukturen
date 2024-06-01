#ifndef STACKWITHLINKEDLIST_H
#define STACKWITHLINKEDLIST_H
#include "SinglyLinkedList.h"

/*
Entwerfen und implementieren Sie einen ADT Stack, der Integer-Werte speichert.
Ihre Stack-Implementierung muss auf verknüpften Listen basieren, was bedeutet, dass die tatsächlichen
Daten Ihres ADT Stack in einer verknüpften Liste und nicht in einem Array gespeichert werden müssen. Um
Ihre Implementierung zu präsentieren, führen Sie Ihren Code aus und zeigen Sie das Ergebnis der folgenden
Operationen nacheinander an.
 */

class Node
{
    public:
        int data;
        Node *next;
};

class StackWithLinkedList
{
    private:
        Node *head;
        int length;
    public:
        StackWithLinkedList();
        ~StackWithLinkedList();
        void push(int value);
        int pop();
        int peek();
        bool isEmpty() const;
        void printStack() const;
};


#endif //STACKWITHLINKEDLIST_H
