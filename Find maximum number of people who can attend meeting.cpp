/*Find maximum number of people who can attend meeting
There is only one room which is holding N meetings that are given as intervals of the form (start[i], end[i], people[i]) where start[i] is the starting time of the ith meeting, end[i] 
is the ending time of the ith meeting, people[i] is the number of people who can attend the ith meeting. At any point of time, the room can be occupied by only one meeting i.e., 
  If two meetings have overlapping intervals then only one of them can be picked. The task is to find the maximum number of people who can attend the meeting.
/*

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Meeting {
    int start;
    int end;
    int people;
};

// Comparator function to sort meetings by their ending time
bool compare(const Meeting &m1, const Meeting &m2) {
    return m1.end < m2.end;
}

int maxPeopleInMeetings(vector<Meeting> &meetings) {
    // Sort meetings based on the ending time
    sort(meetings.begin(), meetings.end(), compare);

    int maxPeople = 0;
    int lastEndTime = 0;

    for (const auto &meeting : meetings) {
        // If the meeting starts after or when the last selected meeting ends
        if (meeting.start >= lastEndTime) {
            // Select this meeting
            maxPeople += meeting.people;
            lastEndTime = meeting.end; // Update the end time to the current meeting's end
        }
    }

    return maxPeople;
}

int main() {
    vector<Meeting> meetings1 = {{5, 8, 3}, {1, 4, 5}, {7, 10, 2}};
    vector<Meeting> meetings2 = {{1, 5, 20}, {3, 8, 50}, {6, 10, 70}};

    cout << "Maximum people in meetings 1: " << maxPeopleInMeetings(meetings1) << endl; // Output: 8
    cout << "Maximum people in meetings 2: " << maxPeopleInMeetings(meetings2) << endl; // Output: 90

    return 0;
}
