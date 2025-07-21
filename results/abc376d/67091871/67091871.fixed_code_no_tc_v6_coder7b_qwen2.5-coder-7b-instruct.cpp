#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN = 200005;
ll n, m, mn = INT_MAX, vis[MAXN];
vector<int> adj[MAXN];

void dfs(int node, int depth) {
    if (vis[node]) return; // Skip already visited nodes
    vis[node] = 1;
    for (int neighbor : adj[node]) {
        if (!vis[neighbor]) { // Only visit unvisited neighbors
            dfs(neighbor, depth + 1);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Assuming undirected graph
    }

    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) { // Start DFS from each unvisited node
            dfs(i, 0);
            mn = min(mn, depth); // Update minimum depth found
        }
    }

    if (mn == INT_MAX) {
        cout << -1;
    } else {
        cout << mn;
    }
    return 0;
}