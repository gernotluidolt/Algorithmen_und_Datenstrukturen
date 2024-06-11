#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include "LinearSearch.h"
#include "BinarySearch.h"

//  to take Time (created with ChatGPT)
template <typename Func>
double measureTime(Func func, const std::vector<int>& arr, int target) {
    auto start = std::chrono::high_resolution_clock::now();
    func(arr, target);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    return duration.count();
}

int main() {
    const int arraySize = 1000000;
    std::vector<int> data(arraySize);

    // fill array with random values
    std::srand(std::time(nullptr));
    for (int& value : data) {
        value = std::rand() % 100000;
    }

    // sort array for binary search
    std::sort(data.begin(), data.end());

    // define target value
    int targetValue = data[std::rand() % arraySize];

    // take time for linear search
    double linearSearchTime = measureTime(linearSearch, data, targetValue);
    linearSearchTime *= 1000;

    // take time for binary search
    double binarySearchTime = measureTime(binarySearch, data, targetValue);
    binarySearchTime *= 1000;

    // print results
    std::cout << "Array size: " << arraySize << '\n';
    std::cout << "Time linear search: " << linearSearchTime << " milliseconds\n";
    std::cout << "Time binary search: " << binarySearchTime << " milliseconds\n";
    std::cout << "Comment:\nI think the time sees a bit fast, maybe there is a mistake in the time measurement\nHowever, binary search is faster than linear search!\n";
    return 0;
}
