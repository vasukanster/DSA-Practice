/* Find Maximum Number of Intersections on the Chart
Given a line chart with n points connected by line segments and a 1-indexed integer array y[], where the ith point has coordinates (i, y[i]). 
There are no horizontal lines, meaning no two consecutive points have the same y-coordinate. The task is to find the maximum number of points of intersection of an infinitely long horizontal line with the chart.
Input: y = [1,2,1,2,1,3,2]
Output: 5
Explanation: As you can see in the image above, the line y = 1.5 has 5 intersections with the chart (in red crosses). You can also see the line y = 2 which intersects the chart in 4 points (in red crosses).
It can be shown that there is no horizontal line intersecting the chart at more than 5 points. So the answer would be 5.

Input: y = [2,1,3,4,5]
Output: 2
Explanation: As you can see in the image above, the line y = 1.5 has 2 intersections with the chart (in red crosses). You can also see the line y = 2 which intersects the chart in 2 points (in red crosses). 
It can be shown that there is no horizontal line intersecting the chart at more than 2 points. So the answer would be 2.
*/

#include <bits/stdc++.h>
using namespace std;

// Function to find the maximum number of intersections with the chart
int maxIntersections(vector<int>& y) {
    int n = y.size(); // Number of points
    unordered_map<double, int> intersectionCount; // Map to count intersections at different heights

    // Loop through pairs of consecutive y-values
    for (int i = 0; i < n - 1; ++i) {
        double minHeight = min(y[i], y[i + 1]); // Minimum y-value of the segment
        double maxHeight = max(y[i], y[i + 1]); // Maximum y-value of the segment

        // For a horizontal line to intersect the segment, it needs to be placed between minHeight and maxHeight
        // We can check all heights between these two y-values
        for (double h = minHeight + 0.5; h < maxHeight; h += 1.0) {
            intersectionCount[h]++; // Count this height
        }
    }

    // Find the maximum value in the intersection counts
    int maxIntersections = 0;
    for (const auto& entry : intersectionCount) {
        maxIntersections = max(maxIntersections, entry.second);
    }

    return maxIntersections; // Return the maximum number of intersections
}

// Driver Code
int main() {
    // Test case 1
    vector<int> y1 = {1, 2, 1, 2, 1, 3, 2};
    cout << "Max Intersections for y1: " << maxIntersections(y1) << endl; // Expected Output: 5

    // Test case 2
    vector<int> y2 = {2, 1, 3, 4, 5};
    cout << "Max Intersections for y2: " << maxIntersections(y2) << endl; // Expected Output: 2

    return 0;
}
