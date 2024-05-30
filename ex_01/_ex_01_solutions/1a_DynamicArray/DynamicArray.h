#ifndef DYNAMICARRAY_H // include guard
#define DYNAMICARRAY_H


class DynamicArrayInteger {
	private:
		int *ptrArr; // points to the array
		int length;  // number elements in the array
		int nextIndex; // index of the next element
	public:
		DynamicArray();
		~DynamicArray();
		int& operator[](int index); // indexing operation
		void add(int val); // add a new value to the end
		int size(); // return length of array
		void printDynamicArray(); // print out the values of array
};


#endif /* DYNAMICARRAY_H */