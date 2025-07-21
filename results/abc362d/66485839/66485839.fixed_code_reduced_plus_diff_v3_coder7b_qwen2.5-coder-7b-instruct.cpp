#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int, int>

const int MAXN = 2e5 + 10;

struct DSU {
    int fa[MAXN], sz[MAXN];

    DSU(int n) {
        iota(fa, fa + n, 0);
        fill(sz, sz + n, 1);
    }

    int find(int x) {
        if (fa[x] != x) fa[x] = find(fa[x]);
        return fa[x];
    }

    void merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;
        if (sz[x] < sz[y]) swap(x, y);
        fa[y] = x;
        sz[x] += sz[y];
    }
};

struct Edge {
    int u, v, w;
    bool operator<(const Edge &rhs) const {
        return w < rhs.w;
    }
};

vector<PII> adj[MAXN];
LL dis[MAXN];
int n, m;

void dijkstra(int src) {
    priority_queue<pair<LL, int>, vector<pair<LL, int>>, greater<pair<LL, int>>> pq;
    pq.push({dis[src], src});
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dis[u]) continue;
        for (auto &[v, w] : adj[u]) {
            LL nd = d + w + min(dis[v], (LL)v);
            if (nd < dis[v]) {
                dis[v] = nd;
                pq.push({nd, v});
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> dis[i];
    }
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    fill(dis + 2, dis + n + 1, LLONG_MAX);
    for (int i = 2; i <= n; ++i) {
        dijkstra(i);
        cout << dis[i] << " ";
    }
    cout << "\n";
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