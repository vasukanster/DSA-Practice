/*Find the point where maximum intervals overlap
Consider a big party where a log register for guest’s entry and exit times is maintained. Find the time at which there are maximum guests in the party. Note that entries in register are not in any order.
Example : 

Input: arrl[] = {1, 2, 9, 5, 5}
       exit[] = {4, 5, 12, 9, 12}
First guest in array arrives at 1 and leaves at 4, 
second guest arrives at 2 and leaves at 5, and so on.

Output: 5
There are maximum 3 guests at time 5.  
*/

#include <bits/stdc++.h>
using namespace std;

//similar like platforms and trains problem
vector<int> findMaxGuests(int Entry[], int Exit[], int N) {
    // Vector to store the result: maximum number of guests and the time
    vector<int> ans;

    // Sort the entry and exit arrays to process events in chronological order
    sort(Entry, Entry + N);
    sort(Exit, Exit + N);

    // Initialize pointers for entry and exit arrays
    int i = 1;  // Pointer for the next entry event
    int j = 0;  // Pointer for the next exit event
    
    // Initialize variables to track maximum guests and current guests
    int max_guests = 1;  // At least one guest will be there initially
    int guests_in = 1;   // Start with the first guest
    int time = Entry[0]; // Start time is the first guest's entry time

    // Loop until we process all guests
    while (i < N && j < N) {
        // If the next entry time is less than or equal to the next exit time
        if (Entry[i] <= Exit[j]) {
            guests_in++; // A new guest arrives, increase count
            
            // Check if the current number of guests exceeds the max recorded
            if (guests_in > max_guests) {
                max_guests = guests_in; // Update maximum guest count
                time = Entry[i];        // Update the time to current entry time
            }
            i++; // Move to the next entry
        } else {
            guests_in--; // A guest departs, decrease count
            j++; // Move to the next exit
        }
    }

    // Store the results: maximum guests and the time at which they are present
    ans.push_back(max_guests);
    ans.push_back(time);
    
    return ans; // Return the result vector
}

// Driver code example
int main() {
    int Entry[] = {1, 2, 9, 5, 5};
    int Exit[] = {4, 5, 12, 9, 12};
    int N = sizeof(Entry) / sizeof(Entry[0]);

    vector<int> result = findMaxGuests(Entry, Exit, N);
    cout << "Maximum number of guests: " << result[0] << endl;
    cout << "Time of maximum guests: " << result[1] << endl;

    return 0;
}
