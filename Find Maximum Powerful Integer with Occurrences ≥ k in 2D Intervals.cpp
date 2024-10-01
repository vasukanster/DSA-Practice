/*Find Maximum Powerful Integer with Occurrences ≥ k in 2D Intervals
Given a 2D integer array of intervals whose length is n where intervals[i]=[start, end] i.e. all integers from start to end inclusive of start and end are also present and we are given an integer k. 
We have to return the powerful integer. A powerful Integer is an integer that occurs atleast k times. If multiple integers have at least k occurrences, we have to return the maximum integer out of 
all those elements, and If no integer occurs at least k times return -1.

Examples:

Input: n = 3, intervals = {{1, 3}, {4, 6}, {3, 4}}, k = 2
Output: 4
Explanation: As we can see that 3 and 4 are the 2 integers that have 2 occurrences (2>=k) so we have 4 in this case as the Powerful integer as it is the maximum element which satisfies the condition.

Input: n = 4, intervals = {{1, 4}, {12, 45}, {3, 8}, {10, 12}}, k = 3
Output: -1
Explanation: As we can see that no integer occurs 3 times so in that case we have to return -1.
*/
#include <bits/stdc++.h>
using namespace std;

//brute force
int powerfullInteger(int n,vector<vector<int>> &intervals,int k){
    // Code here
    /*map<int,int> mp;
    for(auto it: intervals){
         for(int i=it[0];i<=it[1];i++){
             mp[i]++;
         }
    }
    int maxi=-1;
    for(auto it:mp){
         if(it.second>=k){
             maxi=it.first;
         }
    }
    return maxi;
}

//efficient
int powerfullInteger(int n, vector<vector<int>> &intervals, int k) {
    // Create a map to store counts of occurrences
    map<int, int> mp;

    // Populate the map with start and end events
    for (auto it : intervals) {
        mp[it[0]]++;        // Increment count at the start of the interval
        mp[it[1] + 1]--;    // Decrement count just after the end of the interval
    }

    int ans = -1;  // Variable to track the maximum powerful integer
    int temp = 0;  // Variable to maintain the current count of active intervals

    // Iterate through the map to calculate the number of overlapping intervals
    for (auto it : mp) {
        // If the current count is non-negative (start of an interval)
        if (mp[it.first] >= 0) {
            temp += mp[it.first];  // Update the active interval count
            
            // If the current active count is at least k
            if (temp >= k) {
                ans = it.first;      // Update the answer to the current integer
            }
        } else {
            // If the current count is negative (end of an interval)
            if (temp >= k) {
                ans = it.first - 1;  // Update answer to the previous integer
            }
            temp += mp[it.first];     // Update the active interval count
        }
    }

    return ans;  // Return the maximum powerful integer found, or -1 if none exists
}

// Driver code for testing
int main() {
    vector<vector<int>> intervals1 = {{1, 3}, {4, 6}, {3, 4}};
    int k1 = 2;
    cout << powerfullInteger(intervals1.size(), intervals1, k1) << endl; // Output: 4

    vector<vector<int>> intervals2 = {{1, 4}, {12, 45}, {3, 8}, {10, 12}};
    int k2 = 3;
    cout << powerfullInteger(intervals2.size(), intervals2, k2) << endl; // Output: -1

    return 0;
}
