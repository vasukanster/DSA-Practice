/* Minimum Penalty Path
link: https://www.hackerrank.com/challenges/beautiful-path/problem
*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'beautifulPath' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. 2D_INTEGER_ARRAY edges
 *  2. INTEGER A
 *  3. INTEGER B
 */

/*
The key idea is that when traversing the graph, the cost of reaching any vertex can be represented as a bitwise OR of the costs of the edges taken to reach it.
Since the edge weights (costs) can vary, we can potentially generate multiple distinct costs when reaching a vertex from different paths.
The range of costs is limited to 0 to 1023, which is why we use an array of size 1024 to track whether a node has been visited with a specific cost.
*/

int beautifulPath(int n, vector<vector<int>> edges, int A, int B) {
    // Create a 2D vector to track visited costs for each node
    vector<vector<bool>> cost_vis(n + 1, vector<bool>(1024, false));

    // Create an adjacency list to represent the graph
    vector<pair<int, int>> adj[n + 1];
    for (auto it : edges) {
        // For each edge, add the connection to the adjacency list
        adj[it[0]].push_back({it[1], it[2]}); // Add edge from it[0] to it[1] with weight it[2]
        adj[it[1]].push_back({it[0], it[2]}); // Add edge from it[1] to it[0] with weight it[2]
    }

    // Initialize a queue for BFS, starting from node A with initial cost 0
    queue<pair<int, int>> q;
    q.push({0, A}); // Push the starting node with cost 0

    // Mark the starting node with cost 0 as visited
    cost_vis[A][0] = true;

    // Perform BFS
    while (!q.empty()) {
        // Get the current node and its associated cost
        int node = q.front().second; // Current node
        int cost = q.front().first;   // Current cost (using bitwise OR)
        q.pop();                      // Remove the processed node from the queue

        // Explore all adjacent nodes
        for (auto it : adj[node]) {
            int new_node = it.first;      // The neighboring node
            int new_cost = it.second | cost; // Calculate the new cost using bitwise OR

            // If we haven't visited this new node with this cost before
            if (!cost_vis[new_node][new_cost]) {
                cost_vis[new_node][new_cost] = true; // Mark as visited
                q.push({new_cost, new_node}); // Push the new node and cost into the queue
            }
        }
    }

    // Check for any valid cost to reach node B
    for (int i = 0; i < 1024; i++) { // Loop through all possible costs (0 to 1023)
        if (cost_vis[B][i]) { // If we have reached B with cost i
            return i; // Return the minimum cost found
        }
    }
    
    return -1; // If no path to B was found, return -1
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

    string second_multiple_input_temp;
    getline(cin, second_multiple_input_temp);

    vector<string> second_multiple_input = split(rtrim(second_multiple_input_temp));

    int A = stoi(second_multiple_input[0]);

    int B = stoi(second_multiple_input[1]);

    int result = beautifulPath(n,edges, A, B);

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
