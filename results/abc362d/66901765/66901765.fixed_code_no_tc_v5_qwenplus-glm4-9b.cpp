#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> adj[200005];
int dist[200005];
int n, m;
vector<int> values;

void dijkstra(int src, int n) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    fill(dist, dist + n + 1, LLONG_MAX);
    
    pq.push({0, src});
    dist[src] = values[src];
    
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        
        for (int v : adj[u]) {
            if (dist[v] > dist[u] + values[v]) {
                dist[v] = dist[u] + values[v];
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    values.resize(n + 1);
    
    for (int i = 1; i <= n; i++) {
        cin >> values[i];
    }
    
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dijkstra(1, n);
    
    for (int i = 2; i <= n; i++) {
        cout << (dist[i] - values[i]) << " ";
    }
    cout << "\n";
    
    return 0;
}