#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<pair<int, int>> validArrangement(vector<pair<int, int>>& pairs) {
        // Graph adjacency list and degree tracker
        unordered_map<int, list<int>> graph;
        unordered_map<int, int> inOutDeg;

        // Build graph and track in/out degrees
        for (auto& pair : pairs) {
            int start = pair.first, end = pair.second;
            graph[start].push_back(end);
            inOutDeg[start]++;  // Out-degree
            inOutDeg[end]--;    // In-degree
        }

        // Find the start node
        int startNode = pairs[0].first;
        for (auto& [node, degree] : inOutDeg) {
            if (degree == 1) {
                startNode = node;
                break;
            }
        }

        vector<pair<int, int>> path;

        // Hierholzer's algorithm to construct the Eulerian path
        function<void(int)> dfs = [&](int curr) {
            auto& neighbors = graph[curr];
            while (!neighbors.empty()) {
                int next = neighbors.front();
                neighbors.pop_front();
                dfs(next);
                path.emplace_back(curr, next); // Add edge to path in reverse order
            }
        };

        dfs(startNode);

        // Reverse path to get the correct order
        reverse(path.begin(), path.end());
        return path;
    }
};