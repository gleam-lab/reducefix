#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int MAXLOG = 20;

vector<int> adj[MAXN];
int fa[MAXN], dep[MAXN];

int getfa(int x) {
    return fa[x] == x ? x : fa[x] = getfa(fa[x]);
}

void merge(int x, int y) {
    if (dep[x] > dep[y]) swap(x, y);
    fa[x] = y;
    dep[y] = max(dep[y], dep[x] + 1);
}

void dfs(int u, int p) {
    fa[u] = p;
    for (auto v : adj[u]) {
        if (v != p) {
            dep[v] = dep[u] + 1;
            dfs(v, u);
        }
    }
}

int main() {
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; ++i) fa[i] = i;
    
    while (q--) {
        int op, u, v, k;
        cin >> op;
        if (op == 1) {
            cin >> u >> v;
            u = getfa(u), v = getfa(v);
            if (u != v) merge(u, v);
        } else {
            cin >> u >> k;
            u = getfa(u);
            if (k > dep[u]) cout << -1 << '\n';
            else {
                vector<int> nodes;
                for (int i = 1; i <= n; ++i) if (getfa(i) == u && i != u) nodes.push_back(i);
                sort(nodes.begin(), nodes.end());
                cout << nodes[nodes.size() - k] << '\n';
            }
        }
    }

    return 0;
}