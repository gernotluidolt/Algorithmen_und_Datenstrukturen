#include "dynamicarray.h"
#include <iostream>

DynamicArray::DynamicArray() {
    length = ARRAY_INITIAL_LENGTH;
    size = 0;
    array = new int[length];
    boolArray = new bool[length];
    for (int i = 0; i < length; ++i) {
        boolArray[i] = false;
    }
    std::cout << "DynamicArray created." << std::endl;
}

DynamicArray::~DynamicArray() {
    delete[] array;
    delete[] boolArray;
}

void DynamicArray::add(int value) {
    if (size == length) {
        int* temp = new int[length * 2];
        bool* tempBool = new bool[length * 2];
        for (int i = 0; i < length; i++) {
            temp[i] = array[i];
            tempBool[i] = boolArray[i];
        }
        delete[] array;
        delete[] boolArray;
        array = temp;
        boolArray = tempBool;
        length *= 2;
    }
    array[size] = value;
    boolArray[size] = true;
    size++;
    std::cout << value << " was added!" << std::endl;
}

void DynamicArray::addPlaceholder() {
    if (size == length) {
        int* temp = new int[length * 2];
        bool* tempBool = new bool[length * 2];
        for (int i = 0; i < length; i++) {
            temp[i] = array[i];
            tempBool[i] = boolArray[i];
        }
        delete[] array;
        delete[] boolArray;
        array = temp;
        boolArray = tempBool;
        length *= 2;
    }
    array[size] = 0;
    boolArray[size] = false;
    size++;
}

int DynamicArray::countValidValues() {
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (boolArray[i]) {
            count++;
        }
    }
    return count;
}

void DynamicArray::printDynamicArray() {
    std::cout << "\nShow Array:" << std::endl;

    // check if array is empty
    if (size == 0) {
        std::cout << "\tArray is empty!" << std::endl;
        std::cout << "\tArray size: " << length << "\n"<< std::endl;
        return;
    }
    // print array
    std::cout << "\t";
    for (int i = 0; i < length; i++) {
        if (boolArray[i]) {
            std::cout << array[i] << " ";
        }
        else {
            std::cout << "x ";
        }
    }
    int n = countValidValues();
    std::cout << "\n\tArray size: " << length << std::endl;
    std::cout << "\tNumber of valid values: " << n << "\n"<< std::endl;
}

int& DynamicArray::operator[](int index) {
    while (index >= size) {
        addPlaceholder();
    }
    if (!boolArray[index]) {
        boolArray[index] = true;
    }
    return array[index];
}