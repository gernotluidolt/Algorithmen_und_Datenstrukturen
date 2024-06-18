#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <algorithm>

#define SIZE 10000
#define RUNS 10

void recursiveInsertionSort(std::vector<int>& arr, int n) {
    if (n <= 1)
        return;

    recursiveInsertionSort(arr, n - 1);

    int last = arr[n - 1];
    int j = n - 2;

    while (j >= 0 && arr[j] > last) {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = last;
}


void notRecursiveInsertionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// helper to print array
void printArray(const std::vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int main() {
    std::vector<int> arr1(SIZE);
    std::vector<int> arr2(SIZE);

    // fill array randomly
    std::srand(std::time(0));
    for (int i = 0; i < SIZE; i++) {
        int value = std::rand() % 10000;
        arr1[i] = value;
        arr2[i] = value;
    }

    // Time-Taking logic taken from ChatGPT! -> measure time for recursive and non-recursive insertion sort
    double recursiveTime = 0;
    for (int i = 0; i < RUNS; i++) {
        std::vector<int> arr = arr1; // Kopie des Arrays
        auto start = std::chrono::high_resolution_clock::now();
        recursiveInsertionSort(arr, arr.size());
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        recursiveTime += duration.count();
    }
    recursiveTime /= RUNS;

    double notRecursiveTime = 0;
    for (int i = 0; i < RUNS; i++) {
        std::vector<int> arr = arr2; // Kopie des Arrays
        auto start = std::chrono::high_resolution_clock::now();
        notRecursiveInsertionSort(arr);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        notRecursiveTime += duration.count();
    }
    notRecursiveTime /= RUNS;

    // print results
    std::cout << "Avg. time for " << SIZE << " elements:" << std::endl;
    std::cout << "\tRecursive insertion sort: " << recursiveTime << " seconds" << std::endl;
    std::cout << "\tNon recursive insertion sort: " << notRecursiveTime << " seconds" << std::endl;


    // Now onto sorting 50 elements
    std::cout << "\nSorting 50 elements:" << std::endl;
    std::vector<int> arr50(50);

    // fill array randomly
    std::srand(std::time(0));
    for (int i = 0; i < 50; i++) {
        int value = std::rand() % 100;
        arr50[i] = value;
    }
    std::cout << "Array of 50 elements before sorting:" << std::endl;
    printArray(arr50);

    // sort array
    recursiveInsertionSort(arr50, 50);
    std::cout << "\nArray of 50 elements after sorting:" << std::endl;
    printArray(arr50);
    return 0;
}
