#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define INF 1e18

const int MAXN = 2e5 + 10;

struct Edge {
    int to, cost;
    Edge(int _to, int _cost): to(_to), cost(_cost) {}
};

vector<Edge> G[MAXN];

LL dijkstra(int n, int start) {
    vector<LL> dist(n + 1, INF);
    priority_queue<pair<LL, int>, vector<pair<LL, int>>, greater<pair<LL, int>>> pq;
    
    dist[start] = 0;
    pq.push({dist[start], start});
    
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        
        if (d > dist[u]) continue;
        
        for (auto &e : G[u]) {
            int v = e.to;
            LL ndist = d + e.cost;
            
            if (ndist < dist[v]) {
                dist[v] = ndist;
                pq.push({dist[v], v});
            }
        }
    }
    
    return dist[n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) {
        cin >> G[i][0].cost;
    }
    
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    
    for (int i = 2; i <= n; i++) {
        cout << dijkstra(n, i) << " ";
    }
    
    return 0;
}