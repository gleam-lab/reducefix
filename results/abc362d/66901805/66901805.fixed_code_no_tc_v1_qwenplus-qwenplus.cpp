#include <bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 1e18;
const int MAXN = 200005;

vector<pair<int, int>> G[MAXN]; // pair of (neighbor, edge weight)
int dist[MAXN];
int A[MAXN];

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    dist[start] = A[start]; // Start from node 1, include its vertex weight
    pq.push({dist[start], start});
    
    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        
        if (d > dist[u]) continue; // Skip outdated entries
        
        for (auto [v, b] : G[u]) {
            int new_cost = dist[u] + b + A[v]; // Path cost: current path cost + edge weight + next vertex weight
            if (new_cost < dist[v]) {
                dist[v] = new_cost;
                pq.push({dist[v], v});
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N, M;
    cin >> N >> M;
    
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
        dist[i] = INF;
    }
    
    for (int i = 0; i < M; ++i) {
        int u, v, b;
        cin >> u >> v >> b;
        G[u].push_back({v, b});
        G[v].push_back({u, b});
    }
    
    dijkstra(1);
    
    for (int i = 2; i <= N; ++i) {
        cout << dist[i] << " ";
    }
    cout << "\n";
    
    return 0;
}