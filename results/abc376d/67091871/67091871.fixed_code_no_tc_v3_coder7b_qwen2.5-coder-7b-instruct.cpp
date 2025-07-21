#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2 * 100005;
int n, m, mn = INT_MAX, vis[MAXN];
vector<int> adj[MAXN];

// Function to perform DFS and detect cycles containing vertex 1
bool dfs(int node, int parent, int &cycleLength) {
    vis[node] = 1;
    
    for (int neighbor : adj[node]) {
        if (neighbor == parent) continue; // Skip the parent node
        
        if (!vis[neighbor]) {
            if (dfs(neighbor, node, cycleLength)) {
                return true;
            }
        } else {
            // If we encounter a visited node that is not the parent, it means we found a cycle
            if (node == 1 || neighbor == 1) {
                cycleLength = min(cycleLength, abs(node - neighbor) + 1);
                return true;
            }
        }
    }
    
    return false;
}

int main() {
    cin >> n >> m;
    
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Assuming undirected graph for simplicity
    }
    
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            int cycleLength = INT_MAX;
            if (dfs(i, -1, cycleLength)) {
                mn = min(mn, cycleLength);
            }
        }
    }
    
    if (mn == INT_MAX) {
        cout << -1;
    } else {
        cout << mn;
    }
    
    return 0;
}