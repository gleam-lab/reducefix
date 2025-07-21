#include <bits/stdc++.h>
using namespace std;
#define INT long long
#define pb push_back
template <class T>
using V = vector<T>;
template <class T>
using VV = vector<vector<T>>;

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
    V<i64> d(n + 1, 1e18);
    V<bool> vis(n + 1, false);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    VV<int> g(n + 1);
    for (int i = 1; i <= m; ++i) {
        int x, y, c;
        cin >> x >> y >> c;
        g[x].emplace_back(y, c);
        g[y].emplace_back(x, c);
    }
    priority_queue<pair<i64, int>, V<pair<i64, int>>, greater<pair<i64, int>>> pq;
    pq.emplace(a[1], 1); // (current weight, vertex)
    d[1] = a[1];
    while (!pq.empty()) {
        auto [w, x] = pq.top();
        pq.pop();
        if (vis[x]) continue;
        vis[x] = true;
        for (const auto& [y, c] : g[x]) {
            if (d[x] + c + a[y] < d[y]) {
                d[y] = d[x] + c + a[y];
                pq.emplace(d[y], y);
            }
        }
    }
    for (int i = 2; i <= n; ++i) {
        cout << d[i] << (i == n ? "\n" : " ");
    }
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}