#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
vector<int> adj[MAXN];
set<int> s[MAXN];

int par[MAXN], sz[MAXN];

void init(int n) {
    iota(par, par + n + 1, 0);
    fill(sz, sz + n + 1, 1);
}

int find(int u) {
    return (par[u] == u ? u : par[u] = find(par[u]));
}

void unite(int u, int v) {
    u = find(u), v = find(v);
    if (u != v) {
        if (sz[u] > sz[v]) swap(u, v);
        par[u] = v;
        sz[v] += sz[u];
        s[v].insert(s[u].begin(), s[u].end());
        s[v].erase(unique(s[v].begin(), s[v].end()), s[v].end());
        s[u].clear();
    }
}

int getKthLargest(int u, int k) {
    u = find(u);
    if (k > sz[u]) return -1;
    auto it = s[u].rbegin();
    advance(it, k - 1);
    return *it;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    init(n);

    while (q--) {
        int type, u, v;
        cin >> type >> u >> v;
        if (type == 1) {
            unite(u, v);
        } else {
            cout << getKthLargest(v, k) << '\n';
        }
    }

    return 0;
}