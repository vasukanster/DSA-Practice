/*Synchronous Shopping
link: https://www.hackerrank.com/challenges/synchronous-shopping/problem
*/

#include <bits/stdc++.h>
using namespace std;

// Function to perform Dijkstra's algorithm
void dijkstra(int n, vector<int>& fishtypes, vector<vector<pair<int, int>>>& adj, vector<vector<int>>& totalweight) {
    // Priority queue to store (distance, shop, fish types collected) in ascending order of distance
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    // Start from shop 0 with its initial fish types and distance 0
    pq.push({0, 0, fishtypes[0]});

    // Process the queue until it's empty
    while (!pq.empty()) {
        // Extract the top element: current distance, current shop, and fish types collected
        auto [curdist, curshop, curTypeOfFish] = pq.top();
        pq.pop();  // Remove the processed element

        // If we already found a better path for this shop with these fish types, skip it
        if (curdist > totalweight[curshop][curTypeOfFish]) continue;

        // Update the shortest distance to reach this shop with the current fish types
        totalweight[curshop][curTypeOfFish] = curdist;

        // Explore all adjacent shops connected by roads
        for (const auto& [nextshop, weight] : adj[curshop]) {
            // Calculate the new distance to the adjacent shop
            int newdist = curdist + weight;
            // Combine current fish types with those available at the adjacent shop
            int newtype = curTypeOfFish | fishtypes[nextshop];

            // If this new path to the next shop with this fish type combination is shorter
            if (newdist < totalweight[nextshop][newtype]) {
                // Update the distance for the next shop and fish type combination
                totalweight[nextshop][newtype] = newdist; 
                // Push the new state into the priority queue for further processing
                pq.push({newdist, nextshop, newtype});  
            }
        }
    }
}

// Main function to compute the shortest path collecting all fish types
int shop(int n, int k, vector<int>& fishtypes, vector<vector<pair<int, int>>>& adj) {
    // Initialize the total weight matrix with maximum values
    vector<vector<int>> totalweight(n, vector<int>(1 << k, INT_MAX));
    // Run Dijkstra's algorithm to fill the total weight matrix
    dijkstra(n, fishtypes, adj, totalweight);

    int res = INT_MAX;  // Result variable to store the minimum distance found

    // Check all combinations of fish types collected at the last shop (n-1)
    for (int i = 0; i < (1 << k); i++) {
        // If there is no valid path for this combination, skip it
        if (totalweight[n - 1][i] == INT_MAX) continue;

        // Check combinations with another state j
        for (int j = i; j < (1 << k); j++) {
            // Skip if there is no valid path for this combination
            if (totalweight[n - 1][j] == INT_MAX) continue;
            // Check if the combined fish types cover all types (bitmask)
            if ((i | j) == (1 << k) - 1) {  
                // Update the result with the maximum distance of both paths
                res = min(res, max(totalweight[n - 1][i], totalweight[n - 1][j]));
            }
        }
    }

    // Return -1 if no valid combination found, else return the minimum distance
    return (res == INT_MAX) ? -1 : res; 
}

int main() {
    ios::sync_with_stdio(false);  // Optimize I/O
    cin.tie(nullptr);  // Tie the input/output streams

    int n, m, k;  // Number of shops, roads, and types of fish
    cin >> n >> m >> k;

    vector<int> fishtypes(n, 0);  // Vector to store fish types for each shop
    for (int i = 0; i < n; i++) {
        int x;  // Number of fish types available at this shop
        cin >> x;
        for (int j = 0; j < x; j++) {
            int type;  // Type of fish
            cin >> type;
            // Store fish types as a bitmask
            fishtypes[i] |= (1 << (type - 1)); 
        }
    }

    // Create adjacency list for the graph
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++) {
        int shop1, shop2, weight;  // Two shops and the weight of the road between them
        cin >> shop1 >> shop2 >> weight;
        // Add both directions since the roads are bidirectional
        adj[shop1 - 1].emplace_back(shop2 - 1, weight);
        adj[shop2 - 1].emplace_back(shop1 - 1, weight);
    }

    // Call the shop function to compute the result and print it
    int result = shop(n, k, fishtypes, adj);
    cout << result << "\n";

    return 0;  // End of the program
}
