#include "DynamicArray.h"
#include <iostream>

#define ARRAY_INITIAL_LENGTH 10   // arbitrary initial size

using namespace std;


DynamicArray::DynamicArray() 
{
	ptrArr = new int[ARRAY_INITIAL_LENGTH];
	for (int i = 0; i < ARRAY_INITIAL_LENGTH; i++)
		ptrArr[i] = 0;
	length = ARRAY_INITIAL_LENGTH;
	nextIndex = 0;
}


DynamicArray::~DynamicArray()
{
	delete [] ptrArr;
}


int& DynamicArray::operator[](int index) 
{
	int *ptrNewArr; // pointer for new array
	if (index >= length) { // is element in the array?
		ptrNewArr = new int[index + ARRAY_INITIAL_LENGTH]; // allocate a bigger array
		for (int i = 0; i < nextIndex; i++) // copy old values
			ptrNewArr[i] = ptrArr[i];
		for (int j = nextIndex; j < index + ARRAY_INITIAL_LENGTH; j++) // initialize the new locations added
			ptrNewArr[j] = 0;
		length = index + ARRAY_INITIAL_LENGTH; // set length to bigger size
		delete [] ptrArr; // delete the old array
		ptrArr = ptrNewArr; // reassign the new array
	}
	if (index > nextIndex) // set nextIndex past index
		nextIndex = index + 1;
	return *(ptrArr + index); // return a reference to the element
}


void DynamicArray::add(int value) 
{
	int *ptrNewArr;
	if (nextIndex == length) {
		length = length + ARRAY_INITIAL_LENGTH;
		ptrNewArr = new int[length];
		for (int i = 0; i < nextIndex; i++)
			ptrNewArr[i] = ptrArr[i];
		for (int j = nextIndex; j < length; j++)
			ptrNewArr[j] = 0;
		delete [] ptrArr;
		ptrArr = ptrNewArr;
	}
	ptrArr[nextIndex++] = value;
}


int DynamicArray::size() 
{
	return length;
}


void DynamicArray::printDynamicArray()
{
	for (int i = 0; i < length; i++)
		cout << da[i] << " ";
        cout << endl << "Number of elements in the array: " 
             << length << endl;
}
