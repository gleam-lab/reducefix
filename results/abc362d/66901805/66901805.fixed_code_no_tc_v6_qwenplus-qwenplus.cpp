#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 1e18;

vector<pair<int, int>> G[200005];
int dist[200005], A[200005];
bool visited[200005];

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    dist[start] = A[start];
    pq.push({dist[start], start});
    
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        
        if (visited[u]) continue;
        visited[u] = true;
        
        for (auto [v, edge_weight] : G[u]) {
            // Path weight includes:
            // - current path weight to u (dist[u])
            // - edge weight between u and v
            // - vertex weight of v (A[v])
            int new_dist = dist[u] + edge_weight + A[v];
            if (!visited[v] && new_dist < dist[v]) {
                dist[v] = new_dist;
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
    
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        dist[i] = INF;
    }
    
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    
    dijkstra(1);
    
    for (int i = 2; i <= N; i++) {
        cout << dist[i] << " ";
    }
    cout << "\n";
    
    return 0;
}