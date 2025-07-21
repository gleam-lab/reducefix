#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

const int MAXN = 200001;

vector<int> adj[MAXN];  // Adjacency list representation of the graph
int n, m, ans[MAXN];  // n is number of nodes, m is number of edges

void dfs(int u, int depth) {
    ans[u] = min(ans[u], depth);
    for (int v : adj[u]) {
        if (ans[v] == INT_MAX) {  // If v has not been visited or found a shorter path
            dfs(v, depth + 1);
            ans[u] = min(ans[u], ans[v]);  // Update u's shortest path
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        ans[i] = INT_MAX;  // Initialize all distances to infinity
    }

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);  // Add both directions since the graph is undirected
    }

    dfs(1, 0);  // Start DFS from node 1

    // Output the shortest distance to node 1
    for (int i = 2; i <= n; ++i) {  // Start from node 2 since node 1 is the source
        if (ans[i] == INT_MAX) {
            cout << "No path from node 1 to node " << i << endl;
        } else {
            cout << "Minimum distance from node 1 to node " << i << " is " << ans[i] << endl;
        }
    }

    return 0;
}