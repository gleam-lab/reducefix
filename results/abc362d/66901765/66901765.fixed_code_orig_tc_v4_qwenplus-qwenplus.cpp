#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 1e18;

vector<vector<pair<int, int>>> graph(200005);
int A[200005];
int dist[200005];
bool visited[200005];

void dijkstra(int start, int N) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    
    fill(dist, dist + N + 1, INF);
    fill(visited, visited + N + 1, false);
    
    dist[start] = A[start]; // Start node's cost includes its own vertex weight
    pq.push({dist[start], start});
    
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        
        if (visited[u]) continue;
        visited[u] = true;
        
        for (auto [v, edgeCost] : graph[u]) {
            int newCost = d + A[v] + edgeCost;
            if (newCost < dist[v]) {
                dist[v] = newCost;
                pq.push({dist[v], v});
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
    }
    
    for (int i = 0; i < M; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    
    dijkstra(1, N);
    
    for (int i = 2; i <= N; ++i) {
        cout << dist[i] << " ";
    }
    cout << "\n";
    
    return 0;
}