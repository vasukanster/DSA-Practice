/*
Given a two-dimensional array arr[][] of dimensions N * 2 which contains the starting and ending time for N meetings on a given day. The task is to print a list of time slots during which the most number of concurrent meetings can be held.
Examples: 
Input: arr[][] = {{100, 300}, {145, 215}, {200, 230}, {215, 300}, {215, 400}, {500, 600}, {600, 700}} 
Output: [215, 230] 
Explanation: 
The given 5 meetings overlap at {215, 230}.
Input: arr[][] = {{100, 200}, {50, 300}, {300, 400}} 
Output: [100, 200] 
*/

#include <bits/stdc++.h>
using namespace std;

void maxConcurrentMeetingSlot(vector<vector<int>> meetings) {
    // Step 1: Sort meetings based on their start time
    sort(meetings.begin(), meetings.end());
    
    // Step 2: Create a min-heap to track end times of meetings
    priority_queue<int, vector<int>, greater<int>> pq;
    
    // Step 3: Initialize the heap with the end time of the first meeting
    pq.push(meetings[0][1]);
    
    // Variables to track maximum number of concurrent meetings and the time slot
    int max_len = 0;  // Maximum number of concurrent meetings
    int max_start = 0; // Start time of the interval with maximum overlap
    int max_end = 0;   // End time of the interval with maximum overlap
    
    // Step 4: Process each meeting
    for (auto it : meetings) {
        // Remove meetings from the heap that have ended before the current meeting starts
        while (pq.size() > 0 && pq.top() <= it[0]) {
            pq.pop();  // Remove the meeting that has ended
        }
        
        // Step 5: Add the current meeting's end time to the heap
        pq.push(it[1]);
        
        // Step 6: Check if the current number of concurrent meetings is greater than the max found so far
        if (pq.size() > max_len) {
            max_len = pq.size();  // Update maximum count
            max_start = it[0];    // Update start time for max overlap
            max_end = pq.top();    // Update end time for max overlap
        }
    }
    
    // Step 7: Output the time slot with the maximum number of concurrent meetings
    cout << max_start << " " << max_end << endl;
}

// Driver Code
int main() {
    // Given array of meetings
    vector<vector<int>> meetings = { { 100, 200 },
                                      { 50, 300 },
                                      { 300, 400 } };
    
    // Function call
    maxConcurrentMeetingSlot(meetings);
    
    // Another set of meetings
    vector<vector<int>> meetings1 = { {100, 300}, {145, 215}, {200, 230}, 
                                       {215, 300}, {215, 400}, {500, 600}, 
                                       {600, 700} };
                                       
    // Function call for the second set of meetings
    maxConcurrentMeetingSlot(meetings1);
}
