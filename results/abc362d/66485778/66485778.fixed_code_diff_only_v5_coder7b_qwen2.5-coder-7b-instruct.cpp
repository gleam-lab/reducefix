#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 7;
const ll INF = 1e18;

struct Edge {
    int to, cost;
};

vector<Edge> adj[MAXN];
ll dist[MAXN];

void dijkstra(int start, int n) {
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({dist[start], start});
    
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        
        if (d > dist[u]) continue;
        
        for (auto &e : adj[u]) {
            int v = e.to;
            ll nd = d + e.cost;
            
            if (nd < dist[v]) {
                dist[v] = nd;
                pq.push({nd, v});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) {
        cin >> dist[i];
    }
    
    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }
    
    for (int i = 2; i <= n; i++) {
        fill(dist + 1, dist + n + 1, INF);
        dijkstra(1, n);
        cout << dist[i] << " ";
    }
    
    return 0;
}