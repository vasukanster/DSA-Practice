/*
Maximum number of intervals that an interval can intersect
Given an array arr[] consisting of N intervals of the form of [L, R], where L, R denotes the start and end positions of the interval, the task is to count the maximum number of intervals that an interval can intersect with each other.

Examples:
Input: arr[] = {{1, 2}, {3, 4}, {2, 5}}
Output: 3
Explanation: The required set of intervals are {1, 2}, {2, 5}, {3, 4} as {2, 5} intersect all other intervals.

Input: arr[] = {{1, 3}, {2, 4}, {3, 5}, {8, 11}}
Output: 3
Explanation: The required set of intervals are {1, 3}, {2, 4}, {3, 5} as {2, 4} intersect all other intervals.
*

#include <bits/stdc++.h>
using namespace std;

// Function to find the maximum number of intervals that can intersect with any given interval
void findMaxIntervals(vector<pair<int, int>> v, int n) {   
    int maxi = 0; // Variable to store the maximum count of intersecting intervals

    // Loop through each interval to consider it as a reference interval
    for (int i = 0; i < n; i++) {
        int cnt = n; // Assume all intervals intersect with the reference interval
        
        // Loop through all intervals to check for intersections
        for (int j = 0; j < n; j++) {
            // Check if the intervals do not overlap
            if (v[i].second < v[j].first || v[i].first > v[j].second) {
                cnt--; // If they do not overlap, decrease the count
            }
        }
        
        // Update maximum count of intersecting intervals found so far
        maxi = max(maxi, cnt);
    }
    
    // Output the maximum number of intersecting intervals
    cout << maxi << endl;
}

// Driver Code
int main() {
    // Array of intervals represented as pairs
    vector<pair<int, int>> arr = { { 1, 2 }, { 3, 4 }, { 2, 5 } };
    int N = arr.size(); // Number of intervals

    // Function Call
    findMaxIntervals(arr, N); // Find and print the maximum number of intersecting intervals

    return 0;
}
