#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN = 2e5 + 5;
int n, m, mn = INT_MAX;
bool vis[MAXN];

vector<int> adj[MAXN];

void dfs(int node, int parent, int depth) {
    if (vis[node]) {
        // If we encounter a node again and it's not its parent, then we found a cycle
        mn = min(mn, depth - vis[node]);
        return;
    }
    
    vis[node] = depth; // Mark the node with its discovery time
    
    for (auto neighbor : adj[node]) {
        if (neighbor != parent) { // Skip the parent node
            dfs(neighbor, node, depth + 1);
        }
    }
}

int main() {
    cin >> n >> m;
    
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    // Start DFS from node 1
    dfs(1, -1, 1); 

    if (mn == INT_MAX) {
        cout << -1;
    } else {
        cout << mn;
    }
    
    return 0;
}