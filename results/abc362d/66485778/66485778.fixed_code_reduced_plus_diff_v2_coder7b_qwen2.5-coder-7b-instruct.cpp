#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MAXN = 2e5 + 5;

struct DSU {
    vector<int> parent, rank;
    DSU(int n) {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
        rank.resize(n + 1, 0);
    }
    
    int find(int u) {
        return parent[u] = (parent[u] == u ? u : find(parent[u]));
    }
    
    void unite(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu == pv) return;
        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else {
            parent[pu] = pv;
            rank[pv]++;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    vector<pair<int, pair<int, int>>> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].second.first >> edges[i].second.second >> edges[i].first;
    }
    sort(edges.begin(), edges.end());

    DSU dsu(n);
    vector<ll> dist(n + 1, LLONG_MAX);
    vector<bool> visited(n + 1, false);

    for (auto &e : edges) {
        int u = e.second.first, v = e.second.second, w = e.first;
        if (dsu.find(u) != dsu.find(v)) {
            dsu.unite(u, v);
            dist[v] = min(dist[v], dist[u] + w + a[v]);
            if (!visited[v]) {
                visited[v] = true;
                for (auto &child : children[v]) {
                    dist[child] = min(dist[child], dist[v] + a[child]);
                }
            }
        }
    }

    for (int i = 2; i <= n; ++i) {
        cout << dist[i] << " ";
    }
    cout << "\n";

    return 0;
}