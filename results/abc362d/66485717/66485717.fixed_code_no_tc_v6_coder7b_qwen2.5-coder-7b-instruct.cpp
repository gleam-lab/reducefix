#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MAXN = 2 * 100010;
const ll INF = 1e18;

struct Edge {
    int to, cost;
};

vector<Edge> adj[MAXN];
ll dist[MAXN];

void dijkstra(int start, int n) {
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    fill(dist, dist + n + 1, INF);
    dist[start] = 0;
    pq.push({dist[start], start});
    
    while (!pq.empty()) {
        int u = pq.top().second;
        ll du = pq.top().first;
        pq.pop();
        
        if (du > dist[u])
            continue;
        
        for (auto &e : adj[u]) {
            int v = e.to;
            ll dv = du + e.cost + min(dist[u], dist[v]); // Adding the minimum distance between u and v to the edge cost
            
            if (dv < dist[v]) {
                dist[v] = dv;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) {
        cin >> dist[i]; // Reading the initial distances (weights) of the nodes
    }
    
    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }
    
    dijkstra(1, n); // Starting Dijkstra's from node 1
    
    for (int i = 2; i <= n; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;
    
    return 0;
}