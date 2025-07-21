#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int N = 200010;  // Assuming maximum node count is 2e5 + 10

vector<int> adj[N];
int visited[N];
int minDepth = numeric_limits<int>::max();  // Initialize to a large number

void dfs(int node, int depth) {
    if (depth > minDepth) return;  // Pruning to avoid unnecessary processing
    visited[node] = 1;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, depth + 1);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);  // Assuming undirected graph
    }

    // Start DFS from node 1
    dfs(1, 0);

    // If minDepth was updated, return it, otherwise, return -1
    if (minDepth == numeric_limits<int>::max()) {
        cout << -1 << endl;
    } else {
        cout << minDepth << endl;
    }

    return 0;
}