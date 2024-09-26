/*
1042. Flower Planting With No Adjacent
You have n gardens, labeled from 1 to n, and an array paths where paths[i] = [xi, yi] describes a bidirectional path between garden xi to garden yi. In each garden, you want to plant one of 4 types of flowers.

All gardens have at most 3 paths coming into or leaving it.

Your task is to choose a flower type for each garden such that, for any two gardens connected by a path, they have different types of flowers.

Return any such a choice as an array answer, where answer[i] is the type of flower planted in the (i+1)th garden. The flower types are denoted 1, 2, 3, or 4. It is guaranteed an answer exists.
*/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
    // Create an adjacency list for the gardens
    vector<vector<int>> graph(n + 1);
    for (const auto& path : paths) {
        int u = path[0];
        int v = path[1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // Result vector to store the flower types for each garden
    vector<int> flowers(n + 1, 0); // 0 means unassigned

    // Assign flower types to each garden
    for (int garden = 1; garden <= n; ++garden) {
        unordered_set<int> usedFlowers; // To track the flowers used by adjacent gardens

        // Check the adjacent gardens and mark their flowers as used
        for (int neighbor : graph[garden]) {
            if (flowers[neighbor] != 0) {
                usedFlowers.insert(flowers[neighbor]);
            }
        }

        // Assign the smallest available flower type
        for (int flowerType = 1; flowerType <= 4; ++flowerType) {
            if (usedFlowers.find(flowerType) == usedFlowers.end()) {
                flowers[garden] = flowerType;
                break;
            }
        }
    }

    // Return the result excluding the first element (index 0)
    return vector<int>(flowers.begin() + 1, flowers.end());
}

int main() {
    int n = 4; // Number of gardens
    vector<vector<int>> paths = {{1, 2}, {1, 3}, {2, 4}}; // Paths between gardens

    vector<int> result = gardenNoAdj(n, paths);
    cout << "Flower types for gardens: ";
    for (int flower : result) {
        cout << flower << " ";
    }
    cout << endl;

    return 0;
}
