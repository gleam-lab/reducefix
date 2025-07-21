#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 2e5 + 5;
vector<int> g[N];
int n, m, dep[N], par[N];

void dfs(int u, int p) {
    dep[u] = dep[p] + 1;
    par[u] = p;
    for (auto v : g[u]) {
        if (v != p) {
            dfs(v, u);
        }
    }
}

int lca(int u, int v) {
    while (u != v) {
        if (dep[u] > dep[v]) {
            u = par[u];
        } else {
            v = par[v];
        }
    }
    return u;
}

int find_depth(int u) {
    int ans = 0;
    while (u != 1) {
        u = par[u];
        ++ans;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1, -1);

    int query_count;
    cin >> query_count;
    while (query_count--) {
        int u, v;
        cin >> u >> v;
        int l = lca(u, v);
        int depth_u = find_depth(u);
        int depth_v = find_depth(v);
        int depth_l = find_depth(l);
        int result = depth_u + depth_v - 2 * depth_l;
        cout << result << '\n';
    }

    return 0;
}