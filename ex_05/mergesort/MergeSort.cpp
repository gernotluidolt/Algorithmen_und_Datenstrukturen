#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <algorithm>

#define SIZE 10000
#define RUNS 10

void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> leftArr(n1);
    std::vector<int> rightArr(n2);

    for (int i = 0; i < n1; ++i)
        leftArr[i] = arr[left + i];
    for (int i = 0; i < n2; ++i)
        rightArr[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            ++i;
        } else {
            arr[k] = rightArr[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        arr[k] = leftArr[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        arr[k] = rightArr[j];
        ++j;
        ++k;
    }
}

void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

void mergeSort(std::vector<int>& arr) {
    if (arr.size() > 1) {
        mergeSort(arr, 0, arr.size() - 1);
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
        mergeSort(arrTmp);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        totalTime += duration.count();
    }
    double averageTime = totalTime / RUNS;

    // print results
    std::cout << "Avg. time for " << SIZE << " elements using merge sort: " << averageTime << " seconds" << std::endl;

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
    mergeSort(arr50);
    std::cout << "\nArray of 50 elements after sorting:" << std::endl;
    printArray(arr50);

    return 0;
}
