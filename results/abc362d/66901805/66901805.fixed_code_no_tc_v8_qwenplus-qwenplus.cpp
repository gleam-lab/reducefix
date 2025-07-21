#include <bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 1e18;
const int MAXN = 2e5 + 5;

vector<vector<pair<int, int>>> graph(MAXN); // {to, weight}
int A[MAXN];
int dist[MAXN];
bool visited[MAXN];

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    
    dist[start] = 0;
    pq.push({0, start});
    
    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        
        if (visited[u]) continue;
        visited[u] = true;
        
        // Current distance includes vertex weight of u
        for (auto [v, edge_weight] : graph[u]) {
            int new_cost = d + edge_weight + A[v];
            
            if (!visited[v] && new_cost < dist[v]) {
                dist[v] = new_cost;
                pq.push({new_cost, v});
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    cin >> N >> M;
    
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
        dist[i] = INF;
    }
    
    for (int i = 0; i < M; ++i) {
        int u, v, b;
        cin >> u >> v >> b;
        graph[u].push_back({v, b});
        graph[v].push_back({u, b});
    }
    
    // Start from vertex 1
    dist[1] = A[1]; // Path starts at vertex 1, so we include its weight
    
    dijkstra(1);
    
    for (int i = 2; i <= N; ++i) {
        cout << dist[i] << " ";
    }
    cout << "\n";
    
    return 0;
}