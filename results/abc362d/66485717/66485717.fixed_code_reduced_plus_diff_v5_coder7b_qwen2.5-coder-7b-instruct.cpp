#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define INF 1LL << 60

struct DSU {
    vector<LL> par, rank;
    DSU(LL n) {
        par.resize(n + 1); rank.resize(n + 1, 1);
        for (LL i = 0; i <= n; i++) par[i] = i;
    }
    LL getPar(LL x) {
        if (par[x] == x) return x;
        return par[x] = getPar(par[x]);
    }
    void unite(LL x, LL y) {
        x = getPar(x), y = getPar(y);
        if (rank[x] < rank[y]) swap(x, y);
        par[y] = x;
        if (rank[x] == rank[y]) rank[x]++;
    }
};

struct Edge {
    LL u, v, w;
    bool operator<(const Edge &other) const { return w < other.w; }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    LL n, m;
    cin >> n >> m;
    vector<LL> a(n + 1);
    vector<vector<pair<LL, LL>>> adj(n + 1);
    
    for (LL i = 1; i <= n; i++) cin >> a[i];

    for (LL i = 1; i <= m; i++) {
        LL u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    priority_queue<pair<LL, LL>, vector<pair<LL, LL>>, greater<pair<LL, LL>>> pq;
    vector<LL> dist(n + 1, INF);
    dist[1] = a[1];
    pq.push({dist[1], 1});

    while (!pq.empty()) {
        LL u = pq.top().second;
        LL d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto &[v, w] : adj[u]) {
            LL nd = d + w + a[v];
            if (nd < dist[v]) {
                dist[v] = nd;
                pq.push({dist[v], v});
            }
        }
    }

    for (LL i = 2; i <= n; i++) cout << dist[i] << " ";
    cout << endl;

    return 0;
}