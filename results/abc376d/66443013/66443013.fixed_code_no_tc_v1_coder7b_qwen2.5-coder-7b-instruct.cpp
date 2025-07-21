#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<bool> seen;

const int INF = 1e9;

void dfs(int node, int parent, int depth, int &min_edges) {
    if (node == 1 && depth > 0) { // Check if we're back at vertex 1
        min_edges = min(min_edges, depth);
        return;
    }
    
    seen[node] = true;
    
    for (int neighbor : graph[node]) {
        if (neighbor != parent && !seen[neighbor]) {
            dfs(neighbor, node, depth + 1, min_edges);
        }
    }
    
    seen[node] = false; // Reset seen status to allow other paths
}

int main() {
    int n, m;
    cin >> n >> m;
    graph.resize(n + 1);
    seen.resize(n + 1, false);
    
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    
    int min_edges = INF;
    dfs(1, -1, 0, min_edges); // Start DFS from vertex 1
    
    if (min_edges == INF) {
        cout << "-1" << endl;
    } else {
        cout << min_edges << endl;
    }
    
    return 0;
}