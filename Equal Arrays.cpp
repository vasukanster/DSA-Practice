/* Equal Arrays hackerearth problem
*/
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int countMatches(const vector<int>& arr, const vector<int>& B) {
    unordered_set<int> setB(B.begin(), B.end()); // Create a set from B for quick look-up
    unordered_set<int> subarraySums; // Set to store unique subarray sums

    int n = arr.size();

    // Calculate subarray sums
    for (int start = 0; start < n; ++start) {
        int current_sum = 0; // Reset sum for each starting point
        for (int end = start; end < n; ++end) {
            current_sum += arr[end]; // Add the current element to the sum
            subarraySums.insert(current_sum); // Insert the sum into the set
        }
    }

    // Count how many unique subarray sums are in B
    int count = 0;
    for (int sum : subarraySums) {
        if (setB.count(sum)) {
            count++;
        }
    }

    return count; // Return the count of matches
}

int main() {
    vector<int> arr = {1, 3, 2, 2, 3}; // Example array
    vector<int> B = {4, 2, 5}; // Array B

    if (arr.size() < B.size()) { // Check if A can be constructed from B
        cout << -1 << endl; // Print -1 if impossible
        return 0;
    }

    int matches = countMatches(arr, B); // Count matches of B in subarray sums of A
    cout << matches << endl; // Output the result

    return 0;
}
