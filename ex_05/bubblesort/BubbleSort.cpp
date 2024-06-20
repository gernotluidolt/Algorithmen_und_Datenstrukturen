#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <algorithm>

#define SIZE 10000
#define RUNS 10

void bubbleSort(std::vector<int>& arr, int n) {
    bool didSwap = false;
    for (int i = 0; i < n; i++) {
        if (arr[i] > arr[i + 1]) {
            std::swap(arr[i], arr[i + 1]);
            didSwap = true;
        }
    }
    if (didSwap && n > 1) {
        bubbleSort(arr , n - 1);
    }
}

void bubbleSort(std::vector<int>& arr) {
    if (arr.size() > 1) {
        bubbleSort(arr, arr.size() - 1);
    }
}

// helper to print array
void printArray(const std::vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int main() {
    std::vector<int> arr(SIZE);

    // fill array randomly
    std::srand(std::time(0));
    for (int i = 0; i < SIZE; i++) {
        arr[i] = std::rand() % 10000;
    }

    // Time-Taking logic taken from ChatGPT!
    double totalTime = 0;
    for (int i = 0; i < RUNS; i++) {
        std::vector<int> arrTmp = arr; // copy of the array
        auto start = std::chrono::high_resolution_clock::now();
        bubbleSort(arrTmp);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        totalTime += duration.count();
    }
    double averageTime = totalTime / RUNS;

    // print results
    std::cout << "Avg. time for " << SIZE << " elements using bubble sort: " << averageTime << " seconds" << std::endl;

    // Now onto sorting 50 elements
    std::cout << "\nSorting 50 elements:" << std::endl;
    std::vector<int> arr50(50);

    // fill array randomly
    for (int i = 0; i < 50; i++) {
        arr50[i] = std::rand() % 100;
    }
    std::cout << "Array of 50 elements before sorting:" << std::endl;
    printArray(arr50);

    // sort array
    bubbleSort(arr50);
    std::cout << "\nArray of 50 elements after sorting:" << std::endl;
    printArray(arr50);

    return 0;
}
