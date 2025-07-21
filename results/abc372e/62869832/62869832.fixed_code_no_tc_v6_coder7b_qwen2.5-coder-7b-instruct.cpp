#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int LOGN = 20;

vector<int> adj[MAXN];
int parent[MAXN][LOGN], depth[MAXN];

void dfs(int node, int par, int d) {
    parent[node][0] = par;
    depth[node] = d;
    for (int i = 1; i < LOGN; ++i) {
        if (parent[node][i - 1] != -1) {
            parent[node][i] = parent[parent[node][i - 1]][i - 1];
        } else {
            parent[node][i] = -1;
        }
    }
    for (int child : adj[node]) {
        if (child != par) {
            dfs(child, node, d + 1);
        }
    }
}

int getKthAncestor(int node, int k) {
    for (int i = 0; i < LOGN; ++i) {
        if (k & (1 << i)) {
            node = parent[node][i];
        }
    }
    return node;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; ++i) {
        parent[i].assign(LOGN, -1);
    }

    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1, 0);

    while (q--) {
        int type, v, k;
        cin >> type >> v >> k;
        if (type == 1) {
            // No need to handle addition of edges in this problem
        } else {
            int lca = getKthAncestor(v, k);
            cout << lca << "\n";
        }
    }

    return 0;
}