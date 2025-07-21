#include<bits/stdc++.h>
using namespace std;
using ll = long long;
unordered_map<int, vector<int>> graph;
unordered_set<int> seen;

// Function to perform DFS and detect cycle length
void dfs(int node, int parent, int &cycleLength) {
    if (seen.find(node) != seen.end()) {
        // If we encounter a node that has been visited before,
        // calculate the cycle length.
        if (parent == -1 || node != parent) {
            cycleLength += seen.size() - seen.count(node) + 1;
        }
        return;
    }

    seen.insert(node);
    for (auto neighbor : graph[node]) {
        if (neighbor == parent) continue; // Skip the parent node to avoid backtracking
        dfs(neighbor, node, cycleLength);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    int minCycleLength = INT_MAX;
    bool foundCycle = false;

    // Perform DFS for each node to check for cycles
    for (int i = 1; i <= n; ++i) {
        if (!seen.count(i)) {
            int cycleLength = 0;
            dfs(i, -1, cycleLength); // -1 indicates no parent
            if (cycleLength > 0) {
                foundCycle = true;
                minCycleLength = min(minCycleLength, cycleLength);
            }
        }
    }

    if (foundCycle && minCycleLength >= 1) {
        cout << minCycleLength << endl;
    } else {
        cout << "-1" << endl;
    }

    return 0;
}