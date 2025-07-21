#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define INF LLONG_MAX

struct Edge {
    int v, w;
};

vector<Edge> adj[200001];

LL dijkstra(int src, int dest, int n) {
    vector<LL> dist(n+1, INF);
    dist[src] = 0;
    priority_queue<pair<LL, int>, vector<pair<LL, int>>, greater<pair<LL, int>>> pq;
    pq.push({0, src});
    
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        
        for (auto &e : adj[u]) {
            int v = e.v, w = e.w;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist[dest];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        int a; cin >> a;
        for (int j = 1; j <= m; ++j) {
            int b, c; cin >> b >> c;
            adj[a].push_back({b, c});
            adj[b].push_back({a, c});
        }
    }
    
    for (int i = 2; i <= n; ++i) {
        cout << dijkstra(1, i, n) << " ";
    }
    return 0;
}