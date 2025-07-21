#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 2e5 + 5;
int n, m, mn = INT_MAX, vis[maxn];

vector<int> adj[maxn];

void dfs(int node, int depth, int parent) {
    vis[node] = 1;
    for (auto child : adj[node]) {
        if (!vis[child]) {
            dfs(child, depth + 1, node);
        } else if (child != parent) {
            mn = min(mn, depth - vis[child] + 2);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    dfs(1, 0, -1);
    if (mn == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << mn << endl;
    }
    return 0;
}