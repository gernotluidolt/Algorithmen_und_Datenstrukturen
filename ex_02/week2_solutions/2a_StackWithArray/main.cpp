#include "StackWithArray.h"
#include "StackWithArrayException.cpp"
#include <iostream>
#include <exception>

using namespace std;


int main()
{
	StackWithArray stackwa;
   	stackwa.push(23);
   	stackwa.push(9);
   	stackwa.push(70);
	stackwa.printStack();
   	while (!stackwa.isEmpty())
      	{
      		cout << stackwa.pop() << endl;
		stackwa.printStack();
      	}
	try 
	{
		cout << stackwa.peek() << endl;
	}
	catch (StackWithArrayException& e)
    	{
        	cout << e.what() << endl;
    	}
   	return 0;
}