/*239. Sliding Window Maximum
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.
*/
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> result;          // To store the maximums of each sliding window
    deque<int> dq;              // Deque to store indices of elements in the current window

    for (int i = 0; i < nums.size(); i++) {
        // Remove indices that are out of the bounds of the sliding window
        if (!dq.empty() && dq.front() < i - k + 1) {
            dq.pop_front(); // Remove from the front if it's out of the window
        }

        // Remove elements from the back of the deque if they are less than the current element
        while (!dq.empty() && nums[dq.back()] < nums[i]) {
            dq.pop_back(); // Ensure deque only contains indices of elements >= current
        }

        // Add the current element's index to the deque
        dq.push_back(i);

        // Starting from index k - 1, we have the first valid window
        if (i >= k - 1) {
            result.push_back(nums[dq.front()]); // The maximum is at the front of the deque
        }
    }

    return result; // Return the result array
}

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> maxValues = maxSlidingWindow(nums, k);
    cout << "Max sliding window: ";
    for (int val : maxValues) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
