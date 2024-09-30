/* Maximum number of teams that can be formed with given persons
Given two integers N and M which denote the number of persons of Type1 and Type2 respectively. The task is to find the maximum number of teams that can be formed with these two types of persons. 
A team can contain either 2 persons of Type1 and 1 person of Type2 or 1 person of Type1 and 2 persons of Type2.

Examples: 
Input: N = 2, M = 6 
Output: 2 
(Type1, Type2, Type2) and (Type1, Type2, Type2) are the two possible teams.
Input: N = 4, M = 5 
Output: 3 

*/
#include <bits/stdc++.h>
using namespace std;

// Function that returns true if it possible
// to form a team with the given n and m
bool canFormTeam(int n, int m)
{

	// 1 person of Type1 and 2 persons of Type2
	// can be chosen
	if (n >= 1 && m >= 2)
		return true;

	// 1 person of Type2 and 2 persons of Type1
	// can be chosen
	if (m >= 1 && n >= 2)
		return true;

	// Cannot from a team
	return false;
}

// Function to return the maximum number of teams
// that can be formed
int maxTeams(int n, int m)
{
	// To store the required count of teams formed
	int count = 0;

	while (canFormTeam(n, m)) {
		if (n > m) {

			// Choose 2 persons of Type1
			n -= 2;

			// And 1 person of Type2
			m -= 1;
		}
		else {

			// Choose 2 persons of Type2
			m -= 2;

			// And 1 person of Type1
			n -= 1;
		}

		// Another team has been formed
		count++;
	}

	return count;
}

// Driver code
int main()
{
	int n = 4, m = 5;
	cout << maxTeams(n, m);

	return 0;
}
