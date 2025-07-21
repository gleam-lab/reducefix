#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int MAXLOGN = 20;

vector<int> adj[MAXN];
int par[MAXN][MAXLOGN];

void dfs(int node, int parent) {
    par[node][0] = parent;
    for (int i = 1; i < MAXLOGN; ++i) {
        if (par[node][i - 1] != -1) {
            par[node][i] = par[par[node][i - 1]][i - 1];
        } else {
            par[node][i] = -1;
        }
    }
    for (int child : adj[node]) {
        if (child != parent) {
            dfs(child, node);
        }
    }
}

int LCA(int u, int v) {
    if (u == v) return u;
    if (par[u][0] == -1 || par[v][0] == -1) return -1; // No path exists
    if (par[u][0] != par[v][0]) {
        for (int i = MAXLOGN - 1; i >= 0; --i) {
            if (par[u][i] != -1 && par[u][i] != par[v][i]) {
                u = par[u][i], v = par[v][i];
            }
        }
    }
    return par[u][0];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; ++i) {
        adj[i].clear();
        memset(par[i], -1, sizeof(par[i]));
    }

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        } else if (type == 2) {
            int v, k;
            cin >> v >> k;
            vector<int> children;
            for (int child : adj[v]) {
                if (LCA(v, child) == v) {
                    children.push_back(child);
                }
            }
            sort(children.begin(), children.end());
            if (k > children.size()) {
                cout << "-1\n";
            } else {
                cout << children[k - 1] << "\n";
            }
        }
    }

    return 0;
}