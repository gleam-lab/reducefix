#include<bits/stdc++.h>
using namespace std;
#define MAXN 200005
#define LOGN 20

vector<int> adj[MAXN];
int parent[MAXN][LOGN];
int depth[MAXN];

void dfs(int node, int par, int d) {
    parent[node][0] = par;
    depth[node] = d;
    for (int i = 1; i < LOGN; ++i) {
        if (parent[node][i - 1] != -1)
            parent[node][i] = parent[parent[node][i - 1]][i - 1];
    }
    for (auto child : adj[node]) {
        if (child == par) continue;
        dfs(child, node, d + 1);
    }
}

int lca(int u, int v) {
    if (depth[u] > depth[v])
        swap(u, v);

    int diff = depth[v] - depth[u];
    for (int i = 0; i < LOGN; ++i) {
        if ((diff >> i) & 1)
            v = parent[v][i];
    }

    if (u == v) return u;

    for (int i = LOGN - 1; i >= 0; --i) {
        if (parent[u][i] != parent[v][i]) {
            u = parent[u][i];
            v = parent[v][i];
        }
    }

    return parent[u][0];
}

int kthAncestor(int u, int k) {
    for (int i = 0; i < LOGN; ++i) {
        if ((k >> i) & 1)
            u = parent[u][i];
    }
    return u;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; ++i) {
        parent[i][0] = -1;
    }

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        } else {
            int v, k;
            cin >> v >> k;
            if (adj[v].size() < k) {
                cout << "-1" << endl;
            } else {
                int farthest = *max_element(adj[v].begin(), adj[v].end());
                int ancestor = kthAncestor(farthest, k - 1);
                cout << ancestor << endl;
            }
        }
    }

    return 0;
}