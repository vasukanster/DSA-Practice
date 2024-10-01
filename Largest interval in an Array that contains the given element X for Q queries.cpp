/* Largest interval in an Array that contains the given element X for Q queries
Given an array arr[] of N elements and Q queries of the form [X]. For each query, the task is to find the largest interval [L, R] of the array such that the greatest element in the interval is arr[X], such that 1 ? L ? X ? R. 
Note: The array has 1-based indexing.

Examples: 

Input: N = 5, arr[] = {2, 1, 2, 3, 2}, Q = 3, query[] = {1, 2, 4} 
Output: 
[1, 3] 
[2, 2] 
[1, 5] 
Explanation : 
In 1st query, x = 1, so arr[x] = 2 and answer is L = 1 and R = 3. here, we can see that max(arr[1], arr[2], arr[3]) = arr[x], which is the maximum intervals. 
In 2nd query, x = 2, so arr[x] = 1 and since it is the smallest element of the array, so the interval contains only one element, thus the range is [2, 2]. 
In 3rd query, x = 4, so arr[x] = 4, which is maximum element of the arr[], so the answer is whole array, L = 1 and R = N.

Input: N = 4, arr[] = { 1, 2, 2, 4}, Q = 2, query[] = {1, 2} 
Output: 
[1, 1] 
[1, 3] 
Explanation: 
In 1st query, x = 1, so arr[x] = 1 and since it is the smallest element of the array, so the interval contains only one element, thus the range is [1, 1]. 
In 2nd query, x = 2, so arr[x] = 2 and answer is L = 1 and R = 3. here, we can see that max(arr[1], arr[2], arr[3]) = arr[x] = arr[2] = 2, which is the maximum intervals. 
*/
#include <bits/stdc++.h>
using namespace std;

// Function to find the largest interval for each query
void largestInterval(int arr[], int query[], int N, int Q) {
    for (int i = 0; i < Q; i++) {
        int x = query[i]; // Get the index from the query (1-based)
        int value = arr[x]; // Value at the queried index

        int L = x, R = x; // Start with the current index as both L and R

        // Expand left
        while (L > 1 && arr[L - 1] <= value) {
            L--;
        }
        
        // Expand right
        while (R < N && arr[R + 1] <= value) {
            R++;
        }

        // Output the result for the current query
        cout << "[" << L << ", " << R << "]\n";
    }
}

// Driver code
int main() {
    int N = 5, Q = 3;
    int arr[N + 1] = {0, 2, 1, 2, 3, 2}; // 1-based index
    int query[Q] = {1, 2, 4}; // Queries

    // Function call to find the largest intervals
    largestInterval(arr, query, N, Q);
    return 0;
}
