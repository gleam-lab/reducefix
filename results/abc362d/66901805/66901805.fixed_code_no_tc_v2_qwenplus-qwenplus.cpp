#include <bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 1e18;

const int MAXN = 200005;
vector<pair<int, int>> G[MAXN]; // {neighbor, edge_weight}
int A[MAXN];
int dist[MAXN];
bool visited[MAXN];

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    dist[start] = A[start];
    pq.push({dist[start], start});
    
    while (!pq.empty()) {
        int u = pq.top().second;
        int current_dist = pq.top().first;
        pq.pop();
        
        if (visited[u]) continue;
        visited[u] = true;
        
        for (auto [v, edge_cost] : G[u]) {
            // Path cost to v via u:
            // current path cost to u + vertex weight of v + edge weight
            int new_dist = current_dist + A[v] + edge_cost;
            
            if (new_dist < dist[v]) {
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
    
    for (int i = 1; i <= M; i++) {
        int u, v, b;
        cin >> u >> v >> b;
        G[u].push_back({v, b});
        G[v].push_back({u, b});
    }
    
    dijkstra(1);
    
    for (int i = 2; i <= N; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;
    
    return 0;
}