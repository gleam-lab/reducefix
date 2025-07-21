#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define INF 1e18

struct DSU {
    vector<LL> parent, rank;
    DSU(LL n) {
        parent.resize(n+1);
        rank.resize(n+1, 0);
        for (LL i = 0; i <= n; i++) parent[i] = i;
    }
    LL findParent(LL node) {
        if (node == parent[node]) return node;
        return parent[node] = findParent(parent[node]);
    }
    void unionSet(LL u, LL v) {
        LL up = findParent(u);
        LL vp = findParent(v);
        if (up == vp) return;
        if (rank[up] < rank[vp]) {
            parent[up] = vp;
        } else if (rank[up] > rank[vp]) {
            parent[vp] = up;
        } else {
            parent[vp] = up;
            rank[up]++;
        }
    }
};

struct Edge {
    LL u, v, w;
    Edge(LL _u, LL _v, LL _w): u(_u), v(_v), w(_w) {}
    bool operator<(const Edge &other) const {
        return w < other.w;
    }
};

vector<vector<pair<LL, LL>>> adjList;
vector<LL> dist;

void dijkstra(LL src) {
    priority_queue<pair<LL, LL>, vector<pair<LL, LL>>, greater<pair<LL, LL>>> pq;
    dist[src] = 0;
    pq.push({0, src});
    while (!pq.empty()) {
        LL u = pq.top().second;
        LL d = pq.top().first;
        pq.pop();
        if (d > dist[u]) continue;
        for (auto &edge: adjList[u]) {
            LL v = edge.first;
            LL w = edge.second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    LL n, m;
    cin >> n >> m;
    vector<LL> a(n+1);
    for (LL i = 1; i <= n; i++) cin >> a[i];

    adjList.resize(n+1);
    for (LL i = 0; i < m; i++) {
        LL u, v, w;
        cin >> u >> v >> w;
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
    }

    dist.resize(n+1, INF);
    for (LL i = 1; i <= n; i++) dijkstra(i);

    for (LL i = 2; i <= n; i++) cout << dist[i] << " ";
    cout << endl;
    return 0;
}