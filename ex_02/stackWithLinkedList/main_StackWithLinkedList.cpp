#include "StackWithLinkedList.h"
#include "StackWithLinkedListException.cpp"
#include <iostream>
#include <exception>
#include <stdexcept>

int i = 1;

#define STEP std::cout << "STEP " << i++ << std::endl;


int main()
{
    STEP

	StackWithLinkedList stackwll;

    STEP

   	stackwll.printStack();

    STEP

	stackwll.push(100);
   	stackwll.push(200);
   	stackwll.push(300);

    STEP

   	stackwll.printStack();

    STEP

	while (!stackwll.isEmpty())
      	{
            std::cout << stackwll.pop() << std::endl;
		stackwll.printStack();
      	}

    STEP

	try 
	{
        std::cout << stackwll.peek() << std::endl;
	}
	catch (StackWithLinkedListException& e)
    	{
            std::cout << e.what() << std::endl;
    	}

    STEP

	stackwll.push(400);
	try 
	{
        std::cout << stackwll.peek() << std::endl;
   	}
	catch (StackWithLinkedListException& e)
    	{
            std::cout << e.what() << std::endl;
    	}

    STEP

	stackwll.printStack();

    STEP

    stackwll.pop();

    STEP

   	stackwll.printStack();
   	return 0;
}