#include <bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 1e18;

const int MAXN = 2 * 100000 + 5;

vector<pair<int, int>> G[MAXN]; // adjacency list: {neighbor, edge_weight}
int A[MAXN];                    // vertex weights
int dist[MAXN];                 // shortest path distances
bool visited[MAXN];             // for Dijkstra's optimization

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    dist[start] = 0;
    pq.push({0, start});
    
    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        
        if (visited[u]) continue;
        visited[u] = true;
        
        for (auto [v, b] : G[u]) {
            // When moving from u to v, we add:
            // - the edge weight b
            // - the vertex weight A[v]
            // Note: A[u] is already included in dist[u]
            if (dist[v] > d + b + A[v]) {
                dist[v] = d + b + A[v];
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
    }
    
    for (int i = 0; i < M; ++i) {
        int u, v, b;
        cin >> u >> v >> b;
        G[u].push_back({v, b});
        G[v].push_back({u, b});
    }
    
    // Initialize distances
    for (int i = 1; i <= N; ++i) {
        dist[i] = INF;
    }
    
    dijkstra(1);
    
    for (int i = 2; i <= N; ++i) {
        cout << dist[i] << " ";
    }
    cout << endl;
    
    return 0;
}