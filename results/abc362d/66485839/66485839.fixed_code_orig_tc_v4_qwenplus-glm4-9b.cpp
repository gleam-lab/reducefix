#include <bits/stdc++.h>
using namespace std;

#define INT long long 
#define pb push_back

template <class T>
using V = vector<T>;

struct DSU {
    vector<int> fa, sz;
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

INT n, m;
V<INT> a(n + 1, 0);
V<pair<int, int>> g(n + 1);
V<INT> d(n + 1, INT_MAX);

void solve() {
    for (int i = 1; i <= m; ++i) {
        int x, y, c;
        cin >> x >> y >> c;
        g[x].push_back({y, c});
        g[y].push_back({x, c});
    }
    priority_queue<pair<INT, INT>, V<pair<INT, INT>>, greater<pair<INT, INT>>> pq;
    pq.emplace(a[1], 1);  // Start from vertex 1 with weight of vertex 1
    while (!pq.empty()) {
        auto [w, u] = pq.top();
        pq.pop();
        if (d[u] < w) continue;
        for (auto& [v, wc] : g[u]) {
            INT nw = w + wc + a[v];
            if (d[v] > nw) {
                d[v] = nw;
                pq.emplace(nw, v);
            }
        }
    }
    for (int i = 2; i <= n; ++i) {
        cout << d[i] << " ";
    }
    cout << endl;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    solve();
    return 0;
}