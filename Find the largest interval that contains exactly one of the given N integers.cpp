/* Find the largest interval that contains exactly one of the given N integers.
Given an array arr[] of N distinct integers, the task is to find the maximum element in an interval [L, R] such that the interval contains exactly one of the given N integers and 1 ? L ? R ? 105

Input: arr[] = {5, 10, 200} 
Output: 99990 
All possible intervals are [1, 9], [6, 199] and [11, 100000]. 
[11, 100000] has the maximum integers i.e. 99990.
Input: arr[] = {15000, 25000, 40000, 70000, 80000} 
Output: 44999 
 
*/

// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// Function to return the maximum
// size of the required interval
int maxSize(vector<int>& v, int n)
{
    v.push_back(0);
    v.push_back(100001);
    n=n+2;
    sort(v.begin(),v.end());
    int maxi=0;
    for(int i=1;i<(n-1);i++){
        int L=v[i-1]+1;
        int R=v[i+1]-1;
        int diff=R-L+1;
        maxi=max(maxi,diff);
    }
    return maxi;
}

// Driver code
int main()
{
	vector<int> v = { 200, 10, 5 };
	int n = v.size();
	cout << maxSize(v, n);
	return 0;
}
