#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 2e5 + 10;
constexpr i128 INF = 5e18;

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

struct Node {
    int x, w;
    bool operator < (const Node& u) const {
        return w == u.w ? x < u.x : w > u.w;
    }
};

DSU dsu[MAXN];
vector<pair<int, int>> g[MAXN];
priority_queue<Node> pq;

void dijkstra(int n, int start) {
    vector<i128> dist(n + 1, INF);
    vector<bool> vis(n + 1, false);
    dist[start] = dsu[start].size(start);
    pq.emplace(start, dist[start]);
    while (!pq.empty()) {
        auto [x, w] = pq.top();
        pq.pop();
        if (vis[x]) continue;
        vis[x] = true;
        for (const auto& [y, _] : g[x]) {
            if (dsu[x].same(x, y)) continue;
            i128 nw = w + dsu[y].size(y);
            if (dist[x] + nw < dist[y]) {
                dist[y] = dist[x] + nw;
                pq.emplace(y, dist[y]);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1, 0);
    vector<i128> d(n + 1, INF);
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
        dsu[i] = DSU(n);
        dijkstra(n, i);
        for (int j = 1; j <= n; ++j) {
            d[j] = min(d[j], dist[j]);
        }
    }

    for (int i = 2; i <= n; ++i) {
        cout << d[i] + a[i] << " ";
    }
    cout << "\n";

    return 0;
}