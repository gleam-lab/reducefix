#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 5;
const int MAXN = 400005;
vector<pair<int, int>> adj[MAXN];

void addEdge(int u, int v, int w) {
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
}

int dijkstra(int src, int dest) {
    vector<int> dist(MAXN, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    dist[src] = 0;
    pq.push({0, src});
    
    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        
        if (d > dist[u]) continue;
        
        for (auto [v, w]: adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    
    return dist[dest];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, q;
    cin >> n >> m >> q;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i != n || j != m) addEdge(i * m + j, (i + 1) * m + j, 1);
            if (i != n || j != 1) addEdge(i * m + j, (i + 1) * m + j - 1, 1);
            if (i != 1 || j != m) addEdge(i * m + j, (i - 1) * m + j, 1);
            if (i != 1 || j != 1) addEdge(i * m + j, (i - 1) * m + j - 1, 1);
        }
    }
    
    while (q--) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        int node = r * m + c + 1;
        int dist = dijkstra(node, 1);
        if (dist == INF) cout << -1 << endl;
        else cout << dist << endl;
    }
    
    return 0;
}