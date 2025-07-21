#include <bits/stdc++.h>
using namespace std;

#define INT signed
#define pbk push_back
template <class T>
using V = vector<T>;
template <class T>
using VV = vector<vector<T>>;
template <class T>
using VVV = vector<vector<vector<T>>>;

struct DSU {
private:
    vector<int> fa, sz;
public:
    DSU(int n) : fa(n + 1), sz(n + 1, 1) {
        iota(fa.begin(), fa.end(), 0);
    }
    int find(int x) {
        int root = x;
        while (root != fa[root]) {
            root = fa[root];
        }
        while (x != root) {
            int nex = fa[x];
            fa[x] = fa[fa[x]];
            x = nex;
        }
        return root;
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }

    bool merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        if (sz[x] < sz[y]) swap(x, y);
        fa[y] = x;
        sz[x] += sz[y];
        return true;
    }
    int size(int x) {
        return sz[find(x)];
    }
};

struct Edge {
    int x, y, c;
    bool operator < (const Edge& other) const {
        return c < other.c;
    }
};

using i64 = long long;
void solve() {
    int n, m;
    cin >> n >> m;
    V<int> a(n + 1, 0);
    V<i64> d(n + 1, LLONG_MAX);
    V<bool> vis(n + 1, false);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    vector<vector<pair<int, int>>> g(n + 1);
    for (int i = 1; i <= m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        g[u].emplace_back(v, c);
        g[v].emplace_back(u, c);
    }
    
    priority_queue<pair<i64, int>, vector<pair<i64, int>>, greater<pair<i64, int>>> pq;
    pq.emplace(a[1], 1);
    d[1] = a[1];

    while (!pq.empty()) {
        auto [dist, u] = pq.top();
        pq.pop();
        
        if (vis[u]) continue;
        vis[u] = true;

        for (auto [v, cost] : g[u]) {
            if (d[u] + cost + a[v] < d[v]) {
                d[v] = d[u] + cost + a[v];
                pq.emplace(d[v], v);
            }
        }
    }

    for (int i = 2; i <= n; ++i) {
        cout << d[i] << " \n"[i == n];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}