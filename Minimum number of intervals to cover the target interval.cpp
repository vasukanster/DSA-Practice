/* Minimum number of intervals to cover the target interval
Given an array A[] consisting of N intervals and a target interval X, the task is to find the minimum number of intervals from the given array A[] such that they entirely cover the target interval. 
If there doesn’t exist any such interval then print “-1”.

Examples:
Input: A[] = {{1, 3}, {2, 4}, {2, 10}, {2, 3}, {1, 1}}, X = {1, 10}
Output: 2
Explanation:
From the given 5 intervals, {1, 3} and {2, 10} can be selected. Therefore, the points in the range [1, 3] are covered by the interval {1, 3} and the points in the range [4, 10] are covered by the interval {2, 10}.

Input: A[] = {{2, 6}, {7, 9}, {3, 5}, {6, 10}}, X = {1, 4}
Output: -1
Explanation: There exist no set of intervals in the given array A such that they cover the entire target interval.
*/

#include <bits/stdc++.h>
using namespace std;

// Function to find the minimum number of intervals to cover the target interval
int minIntervalsToCoverTarget(vector<pair<int, int>>& intervals, pair<int, int> target) {
    // Sort intervals based on the start time; if equal, by end time descending
    sort(intervals.begin(), intervals.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first == b.first) {
            return a.second > b.second;
        }
        return a.first < b.first;
    });

    int count = 0;
    int currentEnd = target.first; // Start from the beginning of the target interval
    int i = 0;
    int n = intervals.size();

    while (currentEnd < target.second) {
        int maxEnd = currentEnd; // Track the farthest end we can reach
        // While there are intervals that start before or at the current end
        while (i < n && intervals[i].first <= currentEnd) {
            maxEnd = max(maxEnd, intervals[i].second); // Update maxEnd
            i++;
        }
        
        // If we can't extend our coverage, return -1
        if (maxEnd == currentEnd) {
            return -1;
        }
        
        // Move to the next segment
        currentEnd = maxEnd;
        count++;
    }

    return count; // Return the minimum number of intervals
}

// Driver code
int main() {
    vector<pair<int, int>> intervals = {{1, 3}, {2, 4}, {2, 10}, {2, 3}, {1, 1}};
    pair<int, int> target = {1, 10};

    int result = minIntervalsToCoverTarget(intervals, target);
    cout << result << endl; // Output: 2

    vector<pair<int, int>> intervals2 = {{2, 6}, {7, 9}, {3, 5}, {6, 10}};
    pair<int, int> target2 = {1, 4};

    result = minIntervalsToCoverTarget(intervals2, target2);
    cout << result << endl; // Output: -1

    return 0;
}
