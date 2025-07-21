#include <bits/stdc++.h>
using namespace std;

constexpr int N = 200005;
constexpr long long INF = 1e18;
using ll = long long;

struct DSU {
    vector<int> fa, sz;
    DSU(int n) : fa(n + 1), sz(n + 1, 1) { iota(fa.begin(), fa.end(), 0); }
    int find(int x) {
        int root = x;
        while (root != fa[root]) root = fa[root];
        while (x != root) {
            int nex = fa[x];
            fa[x] = root;
            x = nex;
        }
        return root;
    }
    bool merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        if (sz[x] < sz[y]) swap(x, y);
        fa[y] = x;
        sz[x] += sz[y];
        return true;
    }
};

struct Edge {
    int u, v, w;
    bool operator<(const Edge &other) const { return w < other.w; }
};

vector<pair<int, int>> g[N];

void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n + 1);
    vector<ll> d(n + 1, INF);
    vector<bool> vis(n + 1);

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    pq.push({a[1], 1});

    while (!pq.empty()) {
        auto [w, u] = pq.top();
        pq.pop();

        if (vis[u]) continue;
        vis[u] = true;

        for (auto &[v, dw] : g[u]) {
            if (d[u] + dw + a[v] < d[v]) {
                d[v] = d[u] + dw + a[v];
                pq.push({d[v], v});
            }
        }
    }

    for (int i = 2; i <= n; ++i) {
        cout << d[i] << " ";
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}