#include <bits/stdc++.h>
using namespace std;
#define INT signed
#define pb push_back
template <class T>
using V = vector<T>;
template <class T>
using VV = vector<vector<T>>;
template <class T>
using VVV = vector<vector<vector<T>>>;
struct DSU {
    vector<int> fa, sz;
    DSU(int n) : fa(n + 1, 0), sz(n + 1, 1) {}
    int find(int x) {
        return x == fa[x] ? x : fa[x] = find(fa[x]);
    }
    void merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;
        if (sz[x] < sz[y]) swap(x, y);
        fa[x] = y;
        sz[y] += sz[x];
    }
    int size(int x) {
        return sz[find(x)];
    }
};
struct Edge {
    int u, v, w;
    bool operator < (const Edge& other) const {
        return w < other.w;
    }
};
using i64 = long long;
void solve() {
    int n, m;
    cin >> n >> m;
    V<int> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    VV<Edge> g(n + 1);
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({u, v, w});
        g[v].push_back({v, u, w});
    }
    vector<i64> d(n + 1, LLONG_MAX);
    priority_queue<Edge> pq;
    pq.push({1, 1, a[1] + 0}); // Push vertex 1 with 0 as vertex weight
    d[1] = 0;
    while (!pq.empty()) {
        auto [u, v, w] = pq.top();
        pq.pop();
        if (d[u] < w) continue; // Skip if already processed with a smaller or equal value
        for (auto& edge : g[u]) {
            int v = edge.v;
            int weight = edge.w;
            if (d[u] + weight < d[v]) {
                d[v] = d[u] + weight;
                pq.push({u, v, d[v]});
            }
        }
    }
    for (int i = 2; i <= n; ++i) {
        cout << d[i] << (i == n ? "" : " ");
    }
    cout << endl;
}
INT main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}