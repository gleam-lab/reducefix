#include <bits/stdc++.h>
using namespace std;

constexpr int N = 2 * 1e5 + 10;
constexpr int M = 2 * 1e5 + 10;
constexpr int INF = 1e10;

struct DSU {
    vector<int> parent, rank;
    DSU(int n) : parent(n + 1), rank(n + 1, 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }

    void unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;
        if (rank[x] < rank[y]) swap(x, y);
        parent[y] = x;
        if (rank[x] == rank[y]) rank[x]++;
    }
};

struct Edge {
    int u, v, w;
    bool operator<(const Edge &other) const { return w < other.w; }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    vector<Edge> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    sort(edges.begin(), edges.end());

    DSU dsu(n);
    vector<long long> dist(n + 1, INF);
    dist[1] = a[1];

    for (auto &edge : edges) {
        int pu = dsu.find(edge.u), pv = dsu.find(edge.v);
        if (pu == pv) continue;
        dsu.unite(pu, pv);
        dist[pv] = min(dist[pv], dist[pu] + edge.w + a[pv]);
    }

    for (int i = 2; i <= n; ++i) {
        cout << dist[i] << " ";
    }
    cout << "\n";

    return 0;
}