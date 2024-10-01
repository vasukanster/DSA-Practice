/*Maximum number of overlapping Intervals
Given different intervals, the task is to print the maximum number of overlap among these intervals at any time.

Examples: 

Input: v = {{1, 2}, {2, 4}, {3, 6}} 
Output: 2 
The maximum overlapping is 2(between (1 2) and (2 4) or between (2 4) and (3 6)) 
*/

#include <bits/stdc++.h>
using namespace std;

// Function to find the maximum number of overlapping intervals
int overlap(vector<pair<int, int>> intervals, int n) {
    // Create a vector to hold start and end points with corresponding markers
    vector<pair<int, char>> vec;

    // Populate the vector with start and end points of intervals
    for (auto it : intervals) {
        vec.push_back({it.first, 'x'});  // Mark the start of an interval with 'x'
        vec.push_back({it.second, 'y'}); // Mark the end of an interval with 'y'
    }

    // Sort the vector by the points; starts ('x') will come before ends ('y') if they are the same
    sort(vec.begin(), vec.end());

    int ans = 0; // Variable to track the maximum number of overlaps
    int cnt = 0; // Variable to track the current count of overlapping intervals

    // Iterate through the sorted vector to count overlaps
    for (auto it : vec) {
        // If it's a start of an interval, increment the count
        if (it.second == 'x') {
            cnt++;
        } 
        // If it's an end of an interval, decrement the count
        else if (it.second == 'y') {
            cnt--;
        }
        // Update the maximum overlaps found
        ans = max(ans, cnt);
    }

    // Return the maximum number of overlapping intervals found
    return ans;
}

// Driver code for testing
int main() {
    vector<pair<int, int>> intervals = {{1, 2}, {2, 4}, {3, 6}};
    cout << overlap(intervals, intervals.size()) << endl; // Output: 2
    return 0;
}
