#include "StackWithLinkedList.h"
#include "StackWithLinkedListException.cpp"

#include<iostream>

using namespace std;


StackWithLinkedList::StackWithLinkedList() 
{
}


StackWithLinkedList::~StackWithLinkedList() 
{

}


//add element on top of the stack
bool StackWithLinkedList::push(int element)
{
	myStack.insertAtFirst(element); 		
	cout << "Element: " << element << " added to the stack!" << endl;
	return true; 		
}

  
//remove element from the stack
int StackWithLinkedList::pop()
{
   	if (myStack.isEmpty()) 
	{
      		cout << "No elements to remove: Stack underflow!";
     		throw StackWithLinkedListException("No elements to remove: Stack underflow!");
   	}
	else 
	{
		int value = myStack.getFirstNode();
		myStack.removeFirstNode();
		return value;
   	}
}


//remove element from the stack
int StackWithLinkedList::peek()
{
   	if (myStack.isEmpty()) 
	{
      		cout << "No elements to peek: Stack underflow!";
     		throw StackWithLinkedListException("No elements to peek: Stack underflow!");
   	}
	else 
	{
       		return myStack.getFirstNode();
   	}
}

 
bool StackWithLinkedList::isEmpty()
{
	return myStack.isEmpty();
}


void StackWithLinkedList::printStack()
{
	myStack.printList();
}


