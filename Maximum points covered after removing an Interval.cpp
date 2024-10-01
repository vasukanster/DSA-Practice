/* Maximum points covered after removing an Interval
Given N intervals in the form [l, r] and an integer Q. The task is to find the interval which when removed results in the coverage of the maximum number of points (Union of all the rest of the intervals). 
Note that all the given intervals cover numbers between 1 to Q only.

Examples:
Input: intervals[][] = {{1, 4}, {4, 5}, {5, 6}, {6, 7}, {3, 5}}, Q = 7 
Output: Maximum Coverage is 7 after removing interval at index 4 
When last interval is removed we are able to cover the given points using rest of the intervals 
{1, 2, 3, 4, 5, 6, 7}, which is maximum coverage possible. 
(The answer will also be same if we remove interval {4, 5} or {5, 6} )

Input: intervals[][] = {{3, 3}, {2, 2}, {3, 4}}, Q = 4 
Output: Maximum Coverage is 3 after removing interval at index 0 
*/
#include <bits/stdc++.h>
using namespace std;

// Function to find the maximum points covered after removing an interval
int maximumCoverageAfterRemoval(vector<vector<int>>& intervals, int Q) {
    // Step 1: Initialize a coverage array
    vector<int> coverage(Q + 1, 0);

    // Step 2: Fill the coverage array with total coverage
    for (const auto& interval : intervals) {
        int start = interval[0];
        int end = interval[1];
        for (int i = start; i <= end; ++i) {
            coverage[i]++;
        }
    }

    // Step 3: Calculate total points covered
    int totalCovered = 0;
    for (int i = 1; i <= Q; ++i) {
        if (coverage[i] > 0) {
            totalCovered++;
        }
    }

    // Step 4: Try removing each interval and calculating coverage
    int maxCoverage = 0;
    for (int i = 0; i < intervals.size(); ++i) {
        // Get the interval to be removed
        int start = intervals[i][0];
        int end = intervals[i][1];

        // Calculate the contribution of this interval to total coverage
        int currentCoverage = totalCovered;

        // Check how many points in this interval are currently covered
        for (int j = start; j <= end; ++j) {
            if (coverage[j] == 1) {
                currentCoverage--; // This point will be uncovered
            }
        }

        // Update maximum coverage if current is greater
        maxCoverage = max(maxCoverage, currentCoverage);
    }

    return maxCoverage;
}

// Driver code
int main() {
    vector<vector<int>> intervals = {{1, 4}, {4, 5}, {5, 6}, {6, 7}, {3, 5}};
    int Q = 7;
    cout << "Maximum Coverage is " << maximumCoverageAfterRemoval(intervals, Q) << endl;

    intervals = {{3, 3}, {2, 2}, {3, 4}};
    Q = 4;
    cout << "Maximum Coverage is " << maximumCoverageAfterRemoval(intervals, Q) << endl;

    return 0;
}
