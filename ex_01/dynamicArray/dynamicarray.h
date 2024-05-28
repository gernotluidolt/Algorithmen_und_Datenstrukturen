#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#define ARRAY_INITIAL_LENGTH 10

class DynamicArray {
public:
    DynamicArray();
    ~DynamicArray();
    void add(int value);
    void printDynamicArray();
    int& operator[](int index);

private:
    int* array;
    int length;
    int size;
    bool* boolArray;
    void addPlaceholder();
    int countValidValues();
};

#endif // DYNAMICARRAY_H