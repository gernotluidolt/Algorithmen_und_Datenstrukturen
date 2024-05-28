#include "dynamicarray.h"
#include <iostream>

int main() {
    std::cout << "Task 1\n \"x\" represents values in the array that are not valid.\n" << std::endl;

	DynamicArray dynArr;
	
	dynArr.printDynamicArray();
	dynArr.add(100);
	dynArr.add(200);
	dynArr.printDynamicArray();
	dynArr[5] = 500;
	dynArr.printDynamicArray();
	dynArr[21] = 2100;
	dynArr.printDynamicArray();
	return 0;
}