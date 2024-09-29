/*
Given an N horizontal line segments are arranged on the X-axis of a 2D plane. The start and end point of each line segment is given in an Nx2 matrix lines[ ][ ],
the task is to find the maximum number of intersections possible of any vertical line with the given N line segments.
Examples:
Input: N = 4, lines[][] = {{1, 3}, {2, 3}, {1, 2}, {4, 4}}
Output: 3
Explanation: A vertical line at X = 2 passes through {1, 3}, {2, 3}, {1, 2}, ie three of the given horizontal lines.

Input: N = 3, lines[][] = {{1, 3}, {5, 6}, {3, 4}}
Output: 2
Explanation: A vertical line at X = 3 passes through two of the given horizontal lines which are the maximum possible.

*/
#include <bits/stdc++.h>
using namespace std;

// Function to find maximum intersections
int maxIntersections(vector<vector<int> > lines, int N)
{
    // Create a map to store the number of lines at each x-coordinate
    map<int, int> mp;

    // Iterate through each line and update the map accordingly
    for (int i = 0; i < lines.size(); i++) {
        int a = lines[i][0]; // Start of the line
        int b = lines[i][1]; // End of the line
        mp[a]++;             // Increase count at the start point
        mp[b + 1]--;         // Decrease count just after the end point
    }

    // Initialize with minimum value of integer
    int res = INT_MIN; // Variable to track the maximum intersections
    int sum = 0;       // Current count of active lines

    // Iterate through the map and update the sum and maximum accordingly
    for (auto it : mp) {
        sum += it.second; // Update current active lines based on events
        res = max(res, sum); // Check if the current sum is the maximum
    }

    // Return the maximum number of intersections
    return res;
}

// Driver code
int main()
{
    int n = 4; // Number of lines
    vector<vector<int> > mat
        = { { 1, 3 }, { 2, 3 }, { 1, 2 }, { 4, 4 } };

    // Function call
    cout << maxIntersections(mat, n) << endl; // Output the result
}
