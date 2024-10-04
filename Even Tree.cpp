/* Even Tree
link: https://www.hackerrank.com/challenges/even-tree/problem
*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Adjacency list to represent the tree
vector<vector<int>> adj;
// Vector to store the size of each subtree
vector<int> subtree_sizes;

// Depth First Search (DFS) function to calculate subtree sizes
int dfs(int node, int parent) {
    int size = 1; // Initialize size to 1 (counting the current node)
    
    // Iterate over all adjacent nodes (neighbors)
    for (auto it : adj[node]) {
        // Avoid going back to the parent node
        if (it != parent) {
            // Recursively call dfs for the child node
            size += dfs(it, node); // Add the size of the child subtree to the current size
        }
    }
    
    // Store the calculated size of the subtree rooted at 'node'
    subtree_sizes[node] = size;
    return size; // Return the total size of the subtree
}

// Complete the evenForest function
int evenForest(int t_nodes, int t_edges, vector<int> t_from, vector<int> t_to) {
    // Resize the adjacency list and subtree sizes vectors
    adj.resize(t_nodes + 1); // +1 to accommodate 1-based indexing
    subtree_sizes.resize(t_nodes + 1); // Same here for subtree sizes

    // Construct the adjacency list from the edge lists
    for (int i = 0; i < t_edges; i++) {
        // Add edges in both directions since the tree is undirected
        adj[t_from[i]].push_back(t_to[i]);
        adj[t_to[i]].push_back(t_from[i]);
    }
    
    // Start DFS from node 1 (assuming it's the root) with parent as -1 (no parent)
    dfs(1, -1);
    
    int cnt = 0; // Counter for removable edges
    
    // Iterate over all nodes starting from node 2 (we don't check the root)
    for (int i = 2; i <= t_nodes; i++) {
        // Check if the subtree size is even
        if (subtree_sizes[i] % 2 == 0) {
            cnt++; // Increment count of removable edges
        }
    }
    
    return cnt; // Return the count of removable edges
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_nodes_edges_temp;
    getline(cin, t_nodes_edges_temp);

    vector<string> t_nodes_edges = split(rtrim(t_nodes_edges_temp));

    int t_nodes = stoi(t_nodes_edges[0]);
    int t_edges = stoi(t_nodes_edges[1]);

    vector<int> t_from(t_edges);
    vector<int> t_to(t_edges);

    for (int i = 0; i < t_edges; i++) {
        string t_from_to_temp;
        getline(cin, t_from_to_temp);

        vector<string> t_from_to = split(rtrim(t_from_to_temp));

        int t_from_temp = stoi(t_from_to[0]);
        int t_to_temp = stoi(t_from_to[1]);

        t_from[i] = t_from_temp;
        t_to[i] = t_to_temp;
    }

    int res = evenForest(t_nodes, t_edges, t_from, t_to);

    fout << res << "\n";

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
