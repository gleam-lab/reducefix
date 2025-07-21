#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, rank;
    DSU(int n) : parent(n + 1), rank(n + 1, 0) {
        iota(parent.begin(), parent.end(), 0);
    }
    
    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }
    
    void merge(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return;
        if (rank[u] < rank[v]) swap(u, v);
        parent[v] = u;
        if (rank[u] == rank[v]) rank[u]++;
    }
};

struct Edge {
    int u, v, w;
    bool operator<(const Edge &other) const {
        return w < other.w;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    vector<vector<pair<int, long long>>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    priority_queue<Edge> pq;
    for (int i = 1; i <= n; ++i) pq.push({i, a[i]});

    vector<long long> dist(n + 1, LLONG_MAX);
    dist[1] = a[1];
    DSU dsu(n);

    while (!pq.empty()) {
        auto [u, cost] = pq.top();
        pq.pop();

        if (dist[u] < cost) continue;

        for (auto &[v, w] : adj[u]) {
            long long new_cost = cost + w + a[v];
            if (new_cost < dist[v] && dsu.find(u) != dsu.find(v)) {
                dist[v] = new_cost;
                pq.push({v, new_cost});
                dsu.merge(u, v);
            }
        }
    }

    for (int i = 2; i <= n; ++i) {
        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}