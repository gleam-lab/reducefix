#include <bits/stdc++.h>
using namespace std;

#define int long long 

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

using  i64 = long long;

void solve() {}

struct Node {
    int x, w;
    bool operator < (const Node& u) const {
        return w == u.w ? x < u.x : w > u.w;
    }
};

constexpr int N = 3e5 + 10;
constexpr i64 inf = 1e18;
priority_queue<Node> pq;
vector<pair<int, int>> g[N];

void dijkstra(int start, vector<i64>& dist, vector<bool>& visited) {
    pq.emplace(start, dist[start] = 0);
    while (!pq.empty()) {
        auto [u, du] = pq.top(); pq.pop();
        if (visited[u]) continue;
        visited[u] = true;
        for (auto [v, dv] : g[u]) {
            if (dist[u] + dv < dist[v]) {
                dist[v] = dist[u] + dv;
                pq.emplace(v, dist[v]);
            }
        }
    }
}

void solve2() {
    int n, m;
    cin >> n >> m;
    V<int> a(n + 1, 0);
    vector<i64> d(n + 1, inf);
    vector<bool> vis(n + 1, false);

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 1; i <= m; ++i) {
        int x, y, c;
        cin >> x >> y >> c;
        g[x].emplace_back(y, c);
        g[y].emplace_back(x, c);
    }

    for (int i = 1; i <= n; ++i) {
        dijkstra(i, d, vis);
        for (int j = 1; j <= n; ++j) {
            d[j] += a[j];
        }
        for (int j = 2; j <= n; ++j) {
            cout << d[j] << " \n"[j == n];
        }
        fill(d.begin(), d.end(), inf);
        fill(vis.begin(), vis.end(), false);
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve2();
    }
    return 0;
}