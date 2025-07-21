#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

vector<vector<pair<int, int>>> adj;
vector<int> dist;

void dijkstra(int n, int start) {
    dist.resize(n + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();

        if (d > dist[u]) continue;

        for (auto [v, w] : adj[u]) {
            int newDist = d + v + w;

            if (newDist < dist[v]) {
                dist[v] = newDist;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);

    for (int i = 1; i <= n; ++i) {
        int ai;
        cin >> ai;
    }

    for (int i = 1; i <= m; ++i) {
        int u, v, b;
        cin >> u >> v >> b;
        adj[u].emplace_back(v, b);
        adj[v].emplace_back(u, b);
    }

    dijkstra(n, 1);

    for (int i = 2; i <= n; ++i) {
        cout << dist[i] << " ";
    }
    return 0;
}