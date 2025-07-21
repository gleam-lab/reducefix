#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN = 200005;
ll n, m, mn = INT_MAX, vis[MAXN];
vector<int> adj[MAXN];

void dfs(int node, int count) {
    vis[node] = 1;
    for (int neighbor : adj[node]) {
        if (!vis[neighbor]) {
            dfs(neighbor, count + 1);
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
        if (!vis[i]) {
            mn = min(mn, (ll)adj[i].size()); // Minimum degree of any node
        }
    }

    cout << (mn == INT_MAX ? -1 : mn);
    return 0;
}