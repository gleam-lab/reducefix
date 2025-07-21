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
    V<i64> a(n + 1, 0);
    VV<pair<int, i64>> adj(n + 1);

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pbk({v, w});
        adj[v].pbk({u, w});
    }

    VV<i64> dist(n + 1, V<i64>(n + 1, LLONG_MAX));
    priority_queue<pair<i64, pair<int, int>>, vector<pair<i64, pair<int, int>>>, greater<pair<i64, pair<int, int>>>> pq;

    for (int i = 1; i <= n; ++i) {
        dist[i][i] = 0;
        pq.push({a[i], {i, i}});
    }

    while (!pq.empty()) {
        auto [w, p] = pq.top();
        pq.pop();
        int u = p.first, v = p.second;
        if (dist[u][v] < w) continue;

        for (auto& [to, cost] : adj[v]) {
            if (dist[u][to] > w + a[to] + cost) {
                dist[u][to] = w + a[to] + cost;
                pq.push({dist[u][to], {u, to}});
            }
        }
    }

    for (int i = 2; i <= n; ++i) {
        cout << dist[1][i] << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}