/*
To solve the problem of finding the minimum number of subsets with distinct elements from an array, we need to consider the frequency of each element in the array. The goal is to create subsets such that no subset contains duplicate elements.

Approach
Count Frequencies: First, we need to count how many times each element appears in the array. This can be done using a hash map (or an unordered map in C++).

Determine Maximum Frequency: The number of subsets required will be determined by the maximum frequency of any element in the array. If an element appears k times, at least k subsets will be needed to accommodate all occurrences of that element without duplicates.

Steps
Create a frequency map to count occurrences of each element.
Find the maximum value in this frequency map.
The result will be the maximum frequency.
*/

#include <bits/stdc++.h>
using namespace std;

int minSubsetsWithDistinctElements(int arr[], int n) {
    unordered_map<int, int> frequencyMap;

    // Count frequencies of each element
    for (int i = 0; i < n; i++) {
        frequencyMap[arr[i]]++;
    }

    // Find the maximum frequency
    int maxFrequency = 0;
    for (auto& pair : frequencyMap) {
        maxFrequency = max(maxFrequency, pair.second);
    }

    // The answer is the maximum frequency
    return maxFrequency;
}

// Driver code
int main() {
    int arr1[] = {1, 2, 3, 4};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << minSubsetsWithDistinctElements(arr1, n1) << endl; // Output: 1

    int arr2[] = {1, 2, 3, 3};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << minSubsetsWithDistinctElements(arr2, n2) << endl; // Output: 2

    return 0;
}
