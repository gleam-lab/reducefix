#include <bits/stdc++.h>
using namespace std;
#define INT signed
template <class T>
using V = vector<T>;
struct DSU {
private:
    vector<int> fa, sz;
public:
    DSU(int n) : fa(n + 1), sz(n + 1, 1) {
        iota(fa.begin(), fa.end(), 0);
    }
    int find(int x) {
        if (fa[x] != x) fa[x] = find(fa[x]);
        return fa[x];
    }
    bool merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        fa[y] = x;
        sz[x] += sz[y];
        return true;
    }
    int size(int x) {
        return sz[find(x)];
    }
};
struct Edge {
    int from, to, weight;
    bool operator>(const Edge& e) const {
        return weight > e.weight;
    }
};
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    vector<Edge> edges;
    DSU dsu(n + 1);

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.emplace_back(u, v, w);
        edges.emplace_back(v, u, w);
        dsu.merge(u, v);
    }

    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
    vector<long long> dist(n + 1, LLONG_MAX);
    dist[1] = a[1];

    pq.push({1, 1, a[1]});
    while (!pq.empty()) {
        auto [u, du, pa] = pq.top();
        pq.pop();
        if (dist[u] != du) continue;
        for (int v = 1; v <= n; ++v) {
            if (u == v || dsu.size(u) == 1 || dsu.size(v) == 1) continue;
            long long next_dist = du + edges[u].weight + a[v];
            if (next_dist < dist[v]) {
                dist[v] = next_dist;
                pq.push({v, next_dist, edges[u].weight + a[v]});
            }
        }
    }

    for (int i = 2; i <= n; ++i) {
        cout << dist[i] << " ";
    }
    cout << endl;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}