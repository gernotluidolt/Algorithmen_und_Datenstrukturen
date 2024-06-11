#include "StackWithLinkedList.h"
#include "StackWithLinkedListException.cpp"
#include <iostream>
#include <exception>

using namespace std;


int main()
{
	StackWithLinkedList stackwll;
   	stackwll.printStack();
	stackwll.push(100);
   	stackwll.push(200);
   	stackwll.push(300);
   	stackwll.printStack();
	while (!stackwll.isEmpty())
      	{
      		cout << stackwll.pop() << endl;
		stackwll.printStack();
      	}
	try 
	{
		cout << stackwll.peek() << endl;
	}
	catch (StackWithLinkedListException& e)
    	{
        	cout << e.what() << endl;
    	}
	stackwll.push(400);
	try 
	{
		cout << stackwll.peek() << endl;
   	}
	catch (StackWithLinkedListException& e)
    	{
        	cout << e.what() << endl;
    	}
	stackwll.printStack();
      	stackwll.pop();
   	stackwll.printStack();
   	return 0;
}