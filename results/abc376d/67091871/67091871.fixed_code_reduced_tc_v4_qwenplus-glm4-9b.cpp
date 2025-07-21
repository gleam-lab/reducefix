#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n, m, mn = 200005, ans = LLONG_MAX;
vector<int> adj[200005];
bool visited[200005];

void dfs(int node) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Ensure undirected graph
    }
    
    // Start DFS from node 1 (assuming 1-based indexing)
    dfs(1);
    
    // If mn is not updated by DFS, output -1; otherwise, output the minimum value found
    if (ans == LLONG_MAX) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}