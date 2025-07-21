#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define INF 1e18
#define MOD 1e9+7

typedef pair<LL, LL> PLL;

struct DSU {
    vector<LL> parent, rank;
    DSU(LL n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (LL i = 1; i <= n; ++i) parent[i] = i;
    }

    LL findParent(LL node) {
        if (node == parent[node]) return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionSet(LL u, LL v) {
        LL pu = findParent(u), pv = findParent(v);
        if (pu == pv) return;
        if (rank[pu] >= rank[pv]) {
            parent[pv] = pu;
            rank[pu]++;
        } else {
            parent[pu] = pv;
            rank[pv]++;
        }
    }
};

struct Graph {
    vector<vector<pair<LL, LL>>> adj;
    vector<LL> weights;

    Graph(LL n) {
        adj.resize(n + 1);
        weights.resize(n + 1);
    }

    void addEdge(LL u, LL v, LL w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    void dijkstra(LL src, vector<LL>& dist) {
        priority_queue<PLL, vector<PLL>, greater<PLL>> pq;
        dist[src] = weights[src];
        pq.push({dist[src], src});

        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d != dist[u]) continue;
            for (auto [v, w] : adj[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    LL n, m;
    cin >> n >> m;

    Graph g(n);
    DSU dsu(n);
    
    vector<LL> weights(n + 1);
    for (LL i = 1; i <= n; ++i) cin >> weights[i];

    for (LL i = 0; i < m; ++i) {
        LL u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }

    vector<LL> dist(n + 1, INF);
    g.dijkstra(1, dist);

    for (LL i = 2; i <= n; ++i) {
        cout << dist[i] << " ";
    }
    cout << "\n";

    return 0;
}