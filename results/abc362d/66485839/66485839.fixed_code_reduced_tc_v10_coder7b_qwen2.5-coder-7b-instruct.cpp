#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define INF LLONG_MAX
#define pii pair<int, int>

const int MAXN = 2e5 + 10;

struct dsu {
    int fa[MAXN], siz[MAXN];

    dsu(int n) {
        iota(fa, fa + n + 1, 0);
        fill(siz, siz + n + 1, 1);
    }

    int find(int x) {
        return fa[x] == x ? x : fa[x] = find(fa[x]);
    }

    void merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;
        if (siz[x] < siz[y]) swap(x, y);
        fa[y] = x;
        siz[x] += siz[y];
    }
};

struct edge {
    int u, v, w;
    bool operator<(const edge &other) const {
        return w < other.w;
    }
};

vector<edge> es;
vector<vector<pii>> adj(MAXN);

void dijkstra(int n, int start, vector<LL> &dis) {
    dis[start] = 0;
    priority_queue<pair<LL, int>, vector<pair<LL, int>>, greater<pair<LL, int>>> pq;
    pq.push({0, start});
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dis[u]) continue;
        for (auto [v, w] : adj[u]) {
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                pq.push({dis[v], v});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<LL> a(n + 1), dis(n + 1, INF);
    dsu ds(n);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        es.push_back({u, v, w});
    }
    sort(es.begin(), es.end());
    for (auto &e : es) {
        int pu = ds.find(e.u), pv = ds.find(e.v);
        if (pu == pv) continue;
        ds.merge(pu, pv);
        adj[e.u].push_back({e.v, e.w});
        adj[e.v].push_back({e.u, e.w});
    }
    for (int i = 2; i <= n; ++i) {
        dijkstra(n, i, dis);
        cout << dis[1] + a[i] << " ";
    }
    cout << '\n';
    return 0;
}