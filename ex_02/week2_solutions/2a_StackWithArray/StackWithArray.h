#ifndef STACKWITHARRAY_H // include guard
#define STACKWITHARRAY_H

#define STACKWITHARRAY_MAX_SIZE 100


class StackWithArray 
{
	private:
		int top;
   		int myStack[STACKWITHARRAY_MAX_SIZE]; // stack backed by an array
	public:
		StackWithArray();
		~StackWithArray();
   		bool push(int element);
   		int pop();
		int peek();
   		bool isEmpty();
		bool isFull();
		void printStack();
};


#endif /* STACKWITHARRAY_H */