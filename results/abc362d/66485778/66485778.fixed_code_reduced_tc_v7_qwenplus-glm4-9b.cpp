#include <bits/stdc++.h>
using namespace std;

#define INT long long
#define pb push_back

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
    Edge(int a, int b, int c) : x(a), y(b), c(c) {}
    bool operator < (const Edge& other) const {
        return c < other.c;
    }
};

vector <pair<int, int>> g[N];

void solve() {
    int n, m;
    cin >> n >> m;
    vector <INT> a(n + 1, 0);
    vector <INT> d(n + 1, INT_MAX);
    vector <bool> vis(n + 1, false);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        d[i] = a[i]; // Initially set the distance to the vertex weight
    }
    for (int i = 0; i < m; ++i) {
        int x, y, c;
        cin >> x >> y >> c;
        g[x].emplace_back(y, c);
        g[y].emplace_back(x, c);
    }
    priority_queue<Edge> pq;
    pq.emplace(1, INT_MAX, 0); // Start with vertex 1 and its weight 0
    d[1] = 0; // Distance to vertex 1 is 0
    while (!pq.empty()) {
        auto [x, d_from_x, _] = pq.top();
        pq.pop();
        if (vis[x]) continue;
        vis[x] = true;
        for (const auto& [y, dw] : g[x]) {
            INT new_d = d_from_x + dw + a[y];
            if (new_d < d[y]) {
                d[y] = new_d;
                pq.emplace(y, new_d, 0); // Push new distance and 0 for now, will be updated
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
    while (t--) {
        solve();
    }
    return 0;
}