#ifndef STACKWITHLINKEDLIST_H // include guard
#define STACKWITHLINKEDLIST_H

#include "SinglyLinkedList.h" 

#define STACKWITHARRAY_MAX_SIZE 100


class StackWithLinkedList
{
	private:
		SinglyLinkedList myStack; // stack backed by an array
	public:
		StackWithLinkedList();
		~StackWithLinkedList();
   		bool push(int x);
   		int pop();
		int peek();
   		bool isEmpty();
		void printStack();
};


#endif /* STACKWITHLINKEDLIST_H */