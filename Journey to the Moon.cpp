/* Journey to the Moon
link: https://www.hackerrank.com/challenges/journey-to-the-moon/problem

To find the number of ways to form pairs from three sets of sizes 7, 2, and 1, assuming pairs must consist of elements from different sets, we can calculate the pairs that can be formed between each pair of sets and then sum them up.

Let's denote the sets as follows:
Set A: size 7
Set B: size 2
Set C: size 1
Possible Pairs:

Pairs from Set A and Set B:
Each element in Set A can pair with each element in Set B.
Number of pairs = 7×2=14 

Pairs from Set A and Set C:
Each element in Set A can pair with the single element in Set C.
Number of pairs = 7×1=7

Pairs from Set B and Set C:
Each element in Set B can pair with the single element in Set C.
Number of pairs = 2×1=22×1=2
Total Number of Pairs: Now, we can sum the number of pairs from each combination:

Total pairs=(7×2)+(7×1)+(2×1)=14+7+2=23
Thus, the total number of ways to make pairs from these sets, assuming that pairs must consist of elements from different sets, is 23.
*/


#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'journeyToMoon' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY astronaut
 */

class DisjointSet {
public:
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

/*Brute Force to calculate pairings*/
/*int calculatePairing(vector<int>& sets){
    int k = sets.size();
    int totalPairings = 0;
    for(int i=0;i<k;i++){
        for(int j=i+1;j<k;j++){
            totalPairings += sets[i]*sets[j];
        }
    }    
    return totalPairings;
}*/

/*optimal to calculate pairings*/
int calculatePairing(std::vector<int>& sets) {
    int totalSize = 0;
    int totalPairings = 0;
    
    // Calculate the total size of all sets
    for (int size : sets) {
        totalSize += size;
    }

    // Calculate the pairings
    for (int size : sets) {
        totalPairings += size * (totalSize - size);
    }

    // Since each pairing is counted twice, divide by 2
    return totalPairings / 2;
}


int journeyToMoon(int n, vector<vector<int>> astronaut) {
    DisjointSet ds(n);
    for(auto it:astronaut){
        ds.unionBySize(it[0],it[1]);
    }
    vector<int> sets;
    for(int i=0;i<n;i++){
        if(i==ds.findUPar(i)) {
           sets.push_back(ds.size[i]);
        }
    }
    
    int totalPairings = calculatePairing(sets);
    return totalPairings;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int p = stoi(first_multiple_input[1]);

    vector<vector<int>> astronaut(p);

    for (int i = 0; i < p; i++) {
        astronaut[i].resize(2);

        string astronaut_row_temp_temp;
        getline(cin, astronaut_row_temp_temp);

        vector<string> astronaut_row_temp = split(rtrim(astronaut_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int astronaut_row_item = stoi(astronaut_row_temp[j]);

            astronaut[i][j] = astronaut_row_item;
        }
    }

    int result = journeyToMoon(n, astronaut);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
