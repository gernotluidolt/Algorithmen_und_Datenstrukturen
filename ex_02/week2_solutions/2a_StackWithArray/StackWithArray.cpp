#include "StackWithArray.h"
#include "StackWithArrayException.cpp"
#include<iostream>

using namespace std;
  

StackWithArray::StackWithArray() 
{
	top = -1;  // no element on the stack
}


StackWithArray::~StackWithArray() 
{
}


//add element on top of the stack
bool StackWithArray::push(int element)
{
	if (top >= (STACKWITHARRAY_MAX_SIZE-1))
	{
      		cout << "Stack overflow!";
      		return false;  // or could throw an exception
	} else
	{
   		myStack[++top] = element;
   		cout << "Element: " << element << " added to the stack!" << endl;
   		return true; 		
	}
}

  
//remove element from the stack
int StackWithArray::pop()
{
   	if (top < 0) 
	{
      		cout << "No elements to remove: Stack underflow!";
     		throw StackWithArrayException("No elements to remove: Stack underflow!");
   	}
	else 
	{
       		int item = myStack[top--];
      		return item;
   	}
}


//remove element from the stack
int StackWithArray::peek()
{
   	if (top < 0) 
	{
      		cout << "No elements to peek: Stack underflow!";
     		throw StackWithArrayException("No elements to peek: Stack underflow!");
   	}
	else 
	{
       		return myStack[top];
   	}
}

 
//check if stack is empty
bool StackWithArray::isEmpty()
{
	return (top < 0);
}


//check if stack is full
bool StackWithArray::isFull()
{
	if (top >= STACKWITHARRAY_MAX_SIZE-1)
	{
      		return true;
	} else
	{
      		return false;
	}
}


//print the elements in the stack
void StackWithArray::printStack()
{
	cout << "Stack elements: ";
	if (top < 0) 
	{
		cout << "none; stack is empty!" << endl;
		return;
	}
	for (int i=0; i < STACKWITHARRAY_MAX_SIZE-1; ++i)
	{
      		cout << myStack[i] << " ";	
	}
	cout << endl;
}
