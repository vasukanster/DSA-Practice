
/*Minimum Platforms Required for Given Arrival and Departure Times
We are given two arrays that represent the arrival and departure times of trains, the task is to find the minimum number of platforms required so that no train waits.

Examples: 

Input: arr[] = {9:00, 9:40, 9:50, 11:00, 15:00, 18:00}, dep[] = {9:10, 12:00, 11:20, 11:30, 19:00, 20:00} 
Output: 3 
Explanation: There are at-most three trains at a time (time between 9:40 to 12:00)

Input: arr[] = {9:00, 9:40}, dep[] = {9:10, 12:00} 
Output: 1 
Explanation: Only one platform is needed. 
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findPlatform(vector<int> arr, vector<int> dep) {
    // Sort both arrival and departure times
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    int n = arr.size();  // Number of trains
    int platform_needed = 1;  // Current platforms needed
    int max_platforms = 1;  // Maximum platforms needed at a time
    int i = 1;  // Pointer for arrival
    int j = 0;  // Pointer for departure

    while (i < n && j < n) {
        if (arr[i] <= dep[j]) {  // If next train arrives before previous one departs
            platform_needed++;
            i++;
        } else {  // If a train departs before the next one arrives
            platform_needed--;
            j++;
        }

        max_platforms = max(max_platforms, platform_needed);
    }

    return max_platforms;
}

int main() {
    vector<int> arrival_times = {10, 15, 5, 20};
    vector<int> departure_times = {20, 30, 15, 25};
    
    cout << "Minimum platforms required: " << findPlatform(arrival_times, departure_times) << endl;

    return 0;
}
