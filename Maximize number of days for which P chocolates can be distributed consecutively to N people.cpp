/*
Maximize number of days for which P chocolates can be distributed consecutively to N people
Given an integer, P denoting the number of chocolates and an array a[] where ai denotes the type of ith chocolate. There are N people who want to eat chocolate every day. Find the maximum number of consecutive days for which N people can eat chocolates considering the following conditions:

Each of the N people must eat exactly one chocolate on a particular day.
A single person can eat chocolate of the same type only for all days.
Examples:

Input: N = 4, P = 10, arr[] = {1, 5, 2, 1, 1, 1, 2, 5, 7, 2}
Output: 2
Explanation: Chocolates can be assigned in the following way:
Person 1: Type 1
Person 2: Type 1
Person 3: Type 2
Person 4: Type 5
In this way, there are sufficient chocolates for each person to eat one chocolate for two consecutive days. No other possible distribution of chocolates can make the people eat the chocolates for more than 2 days.

Input: N = 3, P = 10, arr[] = {1, 2, 2, 1, 1, 3, 3, 3, 2, 4}
Output: 3
Explanation: Chocolates can be distributed in the following way:
Person 1: Type 1
Person 2: Type 2
Person 3: Type 3
In this way, all the 3 people can eat their respective assigned type of chocolates for three days.
*/

#include <bits/stdc++.h>
using namespace std;

// Function to check if chocolates can be eaten for 'mid' number of days
bool canDistribute(int mid, const unordered_map<int, int>& chocolateCount, int N) {
    int totalDays = 0; // Total groups of 'mid' days we can form

    for (const auto& entry : chocolateCount) {
        totalDays += entry.second / mid; // Count how many full groups of 'mid' can be formed
    }

    return totalDays >= N; // Check if we can satisfy N days
}

// Function to find the maximum number of days for which chocolates can be eaten
int findMaximumDays(int arr[], int P, int N) {
    unordered_map<int, int> chocolateCount; // Frequency of each type of chocolate

    // Count frequencies of chocolates
    for (int i = 0; i < P; i++) {
        chocolateCount[arr[i]]++;
    }

    int start = 1, end = P, maxDays = 0; // Start from 1 since 0 days is not valid

    // Perform binary search to find the maximum number of days
    while (start <= end) {
        int mid = start + (end - start) / 2; // Avoid overflow

        // Check if chocolates can be distributed for 'mid' days
        if (canDistribute(mid, chocolateCount, N)) {
            maxDays = mid; // Update maxDays
            start = mid + 1; // Try for more days
        } else {
            end = mid - 1; // Try fewer days
        }
    }

    return maxDays; // Return the maximum number of days
}

// Driver code
int main() {
    int N = 3; // Number of days chocolates must last
    int P = 10; // Number of chocolates
    int arr[] = { 1, 2, 2, 1, 1, 3, 3, 3, 2, 4 };

    // Function call
    cout << findMaximumDays(arr, P, N) << endl; // Output: Maximum days chocolates can be eaten

    return 0;
}
