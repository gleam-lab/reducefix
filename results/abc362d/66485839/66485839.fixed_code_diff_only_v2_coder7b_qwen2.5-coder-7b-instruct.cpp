#include <bits/stdc++.h>
using namespace std;

#define LL long long

struct Edge {
    int u, v, w;
    bool operator<(const Edge &other) const {
        return w < other.w;
    }
};

vector<Edge> edges;
vector<pair<int, int>> adj[200010];
LL dis[200010];

void dijkstra(int src, int n) {
    fill(dis, dis+n+1, LLONG_MAX);
    priority_queue<pair<LL, int>, vector<pair<LL, int>>, greater<pair<LL, int>>> pq;
    pq.push({0, src});
    dis[src] = 0;
    
    while (!pq.empty()) {
        auto [dist, node] = pq.top(); pq.pop();
        
        if (dist > dis[node]) continue;
        
        for (auto &[neigh, wt]: adj[node]) {
            if (dis[node] + wt < dis[neigh]) {
                dis[neigh] = dis[node] + wt;
                pq.push({dis[neigh], neigh});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> dis[i];

    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    dijkstra(1, n);

    for (int i = 2; i <= n; i++) cout << dis[i] << " ";
    cout << '\n';

    return 0;
}