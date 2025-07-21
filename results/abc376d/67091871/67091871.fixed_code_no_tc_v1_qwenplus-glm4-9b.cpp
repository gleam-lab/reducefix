#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll MOD = 1e6 + 5;
ll n, m, mn = MOD, vis[MOD];
vector<int> adj[MOD];

ll dfs(int node, ll cnt) {
    vis[node] = 1;
    mn = min(mn, cnt + 1);  // Update mn with cnt + 1 initially

    for (int neighbor : adj[node]) {
        if (!vis[neighbor]) {
            dfs(neighbor, cnt + 1);
        }
    }
    return mn;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    // Start DFS from node 1
    dfs(1, 0);

    if (mn == MOD) {
        cout << -1;
    } else {
        cout << mn;
    }
    return 0;
}