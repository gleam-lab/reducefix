#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN = 2e5 + 5;

int n, m, mn = INT_MAX, vis[MAXN];
vector<int> adj[MAXN];

void dfs(int node, int depth) {
    vis[node] = 1;
    int ans = depth + 1;
    bool foundOne = false;
    for (auto neighbor : adj[node]) {
        if (!vis[neighbor] || neighbor == 1) {
            if (neighbor == 1) {
                mn = min(mn, ans);
                return;
            } else {
                dfs(neighbor, ans);
                foundOne = true;
            }
        }
    }
    if (!foundOne && depth > 0) {
        mn = min(mn, depth);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Assuming undirected graph
    }
    dfs(1, 0);
    if (mn == INT_MAX) {
        cout << -1;
    } else {
        cout << mn;
    }
    return 0;
}