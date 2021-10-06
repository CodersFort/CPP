#include <sstream>
#include <iterator>
#include <functional>
#include <vector>
#include <array>
#include <algorithm>
#include <cmath>
#include <string>
#include <bits/stdc++.h>
#include <type_traits>
#include <utility>
#include <iomanip>
#include <iostream>
/*!
 * This function implements the Radix Sorting Algorithm based on the **less significant digit** (LSD).
 * 
 * @note This is a non-comparison sort algorithm. This version only works for non-negative integers.
 *
 * @param arr Array to be sorted.
 * @param n Number of elements in arr.
 */

void radix(int arr[], int n) {    
    // the number of digits of max element indicates how many times the main loop will be executed 
    int max_d = std::to_string(*std::max_element(arr, arr+n)).size(); 

    // one bucket for each digit from 0 to 9
    std::array<std::vector<int>, 10> buckets;

    // main loop; max_d times
    for(int i = 0; i < max_d; i++) {
        // inter loop; insert each element into its respective bucket depending on which digit position is being analyzed
        std::for_each(arr, arr + n, [&buckets, i](int value){ buckets[(int)(value/std::pow(10, i))%10].push_back(value); });
        
        // ==============================================================
        // What the for_each above does is:
        // --------------------------------------------------------------
        // Assuming value = 123 and that the largest number in the collection has 4 digits.
        // 1st pass: 123/1 = 123; 123 % 10 = 3. buckets[3].push_back(123).
        // 2nd pass: 123/10 = 12; 12 % 10 = 2.  buckets[2].push_back(123).
        // 3rd pass: 123/100 = 1; 1 % 10 = 1.   buckets[1].push_back(123).
        // 4th pass: 123/1000 = 0; 0 % 10 = 0.  buckets[0].push_back(123).
        // ==============================================================
 
        // copy from buckets to the original range
        auto destination = arr;
        for(auto &b : buckets) {
            destination = std::copy(b.begin(), b.end(), destination);
            b.clear();
        }
    }
}

void printArray(int arr[], int size) {  
    for(int i = 0; i < size; i++) std::cout << arr[i] << " "; 
    std::cout << std::endl; 
} 

int main() {  
    int arr[] = {23, 10, 20, 11, 12, 6, 7};  
    int n = sizeof(arr)/sizeof(arr[0]);  
  
    radix(arr, n);  
  
    std::cout << "Sorted Array: ";
    printArray(arr, n);  
  
    return 0;  
}  