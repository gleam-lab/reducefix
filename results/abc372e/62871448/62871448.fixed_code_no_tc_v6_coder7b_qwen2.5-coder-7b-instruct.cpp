#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int MAXLOG = 20;

vector<int> adj[MAXN];
int parent[MAXN][MAXLOG];
int depth[MAXN];

void dfs(int node, int par) {
    parent[node][0] = par;
    depth[node] = (par == -1 ? 0 : depth[par] + 1);
    for (int i = 1; i <= MAXLOG; ++i) {
        if (parent[node][i - 1] != -1)
            parent[node][i] = parent[parent[node][i - 1]][i - 1];
    }
    for (int child : adj[node]) {
        if (child != par) {
            dfs(child, node);
        }
    }
}

int lca(int u, int v) {
    if (depth[u] > depth[v]) swap(u, v);
    int diff = depth[v] - depth[u];
    for (int i = 0; i <= MAXLOG; ++i) {
        if ((diff >> i) & 1) {
            v = parent[v][i];
        }
    }
    if (u == v) return u;
    for (int i = MAXLOG; i >= 0; --i) {
        if (parent[u][i] != parent[v][i]) {
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return parent[u][0];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1);

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, v;
            cin >> u >> v;
            cout << lca(u, v) << "\n";
        } else {
            int v, k;
            cin >> v >> k;
            // Assuming the question asks for the k-th smallest ancestor
            // This is a simplification based on the original problem statement
            cout << parent[v][k - 1] << "\n";
        }
    }

    return 0;
}