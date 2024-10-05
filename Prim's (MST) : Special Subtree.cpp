/*Prim's (MST) : Special Subtree
link: https://www.hackerrank.com/challenges/primsmstsub/problem
*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'prims' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY edges
 *  3. INTEGER start
 */

int prims(int n, vector<vector<int>> edges, int start) {
    // Create an adjacency list to represent the graph.
    vector<pair<int,int>> adj[n+1];
    
    // Populate the adjacency list with edges.
    for(auto it:edges) {
        // Each edge is represented as {destination, weight}
        adj[it[0]].push_back({it[1], it[2]}); // Add edge from it[0] to it[1] with weight it[2]
        adj[it[1]].push_back({it[0], it[2]}); // Add edge from it[1] to it[0] with weight it[2]
    }

    // Vector to track visited nodes (0 for not visited, 1 for visited)
    vector<int> vis(n+1, 0);
    
    // Min-heap priority queue to select the edge with the smallest weight
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    // Start with the initial node, push {weight, node} into the priority queue
    pq.push({0, start});
    
    // Mark the starting node as visited (vis[0] is unused since nodes start from 1)
    vis[start] = 0;
    
    // Variable to accumulate the total weight of the MST
    int mst = 0;

    // While there are still edges to explore
    while(!pq.empty()) {
        // Get the node with the smallest weight edge from the priority queue
        int node = pq.top().second; // Current node
        int dis = pq.top().first; // Weight of the edge leading to the current node
        pq.pop(); // Remove this edge from the queue

        // If the node has already been visited, skip it
        if(vis[node] == 1)
            continue;
        
        // Mark this node as visited
        vis[node] = 1;

        // Add the weight of the edge to the total MST weight
        mst += dis;

        // Iterate through all adjacent nodes of the current node
        for(auto it:adj[node]) {
            int adjnode = it.first; // Neighbor node
            int adjdis = it.second; // Weight of the edge to the neighbor
            
            // If the neighbor hasn't been visited yet
            if(!vis[adjnode]) {
                // Add the edge to the priority queue
                pq.push({adjdis, adjnode});
            }
        }   
    }
    
    // Return the total weight of the minimum spanning tree
    return mst;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    vector<vector<int>> edges(m);

    for (int i = 0; i < m; i++) {
        edges[i].resize(3);

        string edges_row_temp_temp;
        getline(cin, edges_row_temp_temp);

        vector<string> edges_row_temp = split(rtrim(edges_row_temp_temp));

        for (int j = 0; j < 3; j++) {
            int edges_row_item = stoi(edges_row_temp[j]);

            edges[i][j] = edges_row_item;
        }
    }

    string start_temp;
    getline(cin, start_temp);

    int start = stoi(ltrim(rtrim(start_temp)));

    int result = prims(n, edges, start);

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
