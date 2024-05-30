#include "DynamicArray.h"
#include <iostream>

using namespace std;


int main() {
	DynamicArray dynArr; // create array of size ARRAY_INITIAL_LENGTH
	
	dynArr.printDynamicArray();
	dynArr.add(100);     // add value to the end
	dynArr.add(200);
	dynArr.printDynamicArray();
	dynArr[5] = 500;
	dynArr.printDynamicArray();
	dynArr[12] = 1212; // set element past the end of the array
	dynArr.printDynamicArray();
	return 0;
}