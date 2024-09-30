/* Maximum number of segments that can contain the given points
Given an array arr[] containing N integers and two integers X and Y. Consider N line segments, where each line segment has starting and ending point as arr[i] – X and arr[i] + Y respectively. 
Given another array b[] of M points. The task is to assign these points to segments such that the number of segments that have been assigned a point is maximum. 
Note that a point can be assigned to at most 1 segment.
Examples: 

Input: arr[] = {1, 5}, b = {1, 1, 2}, X = 1, Y = 4 
Output: 1 
Line Segments are [1-X, 1+Y] , [5-X, 5+Y] i.e. [0, 5] and [4, 9] 
The point 1 can be assigned to the first segment [0, 5] 
No points can be assigned to the second segment. 
So 2 can also be assigned to the first segment but it will not maximize the no. of segment. 
So the answer is 1.
Input: arr[] = {1, 2, 3, 4}, b = {1, 3, 5}, X = 0, Y = 0 
Output: 2 
*/

#include <bits/stdc++.h>
using namespace std;

int maxSegments(vector<int>& arr, vector<int>& b, int X, int Y) {
    vector<pair<int, int>> segments; // To store segments as (start, end)

    // Create segments based on arr, X, and Y
    for (int i = 0; i < arr.size(); i++) {
        int start = arr[i] - X;
        int end = arr[i] + Y;
        segments.push_back({start, end});
    }

    // Sort segments by their ending points
    sort(segments.begin(), segments.end(), [](pair<int, int>& a, pair<int, int>& b) {
        return a.second < b.second;
    });

    // Sort points
    sort(b.begin(), b.end());

    int count = 0; // Count of segments that can contain points
    int j = 0; // Pointer for segments

    // Iterate through points to find how many can be assigned
    for (int point : b) {
        // Move the segment pointer to the first segment that can contain the point
        while (j < segments.size() && segments[j].second < point) {
            j++; // Skip segments that end before the point
        }
        // If we found a segment that contains the point
        if (j < segments.size() && segments[j].first <= point) {
            count++; // Assign this point to the segment
            j++; // Move to the next segment for future points
        }
    }

    return count; // Return the count of segments assigned points
}

// Driver code
int main() {
    vector<int> arr = {1, 5};
    vector<int> b = {1, 1, 2};
    int X = 1, Y = 4;
    cout << maxSegments(arr, b, X, Y) << endl; // Output: 1

    vector<int> arr2 = {1, 2, 3, 4};
    vector<int> b2 = {1, 3, 5};
    int X2 = 0, Y2 = 0;
    cout << maxSegments(arr2, b2, X2, Y2) << endl; // Output: 2

    return 0;
}
