#include<bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 9e18;

vector<vector<pair<int, int>>> G(200005);
int dist[200005], A[200005];
bool vis[200005];

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[start] = A[start];
    pq.push({dist[start], start});
    
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        
        if (vis[u]) continue;
        vis[u] = true;
        
        for (auto [v, w] : G[u]) {
            int new_cost = dist[u] + w + A[v];
            if (new_cost < dist[v]) {
                dist[v] = new_cost;
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
        dist[i] = INF;
    }
    
    for (int i = 0; i < M; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    
    dijkstra(1);
    
    for (int i = 2; i <= N; ++i) {
        cout << dist[i] << " ";
    }
    cout << endl;
    
    return 0;
}