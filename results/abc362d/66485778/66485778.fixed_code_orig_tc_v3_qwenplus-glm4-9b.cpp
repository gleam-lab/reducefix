#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

const int N = 200010;
vector<pair<int, int>> adj[N]; // adj[i] = (j, weight) where there's an edge from i to j

typedef long long ll;
ll dist[N];

void dijkstra(int source) {
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, source});
    dist[source] = 0;
    
    while (!pq.empty()) {
        auto [d, node] = pq.top();
        pq.pop();
        
        if (dist[node] < d) continue;
        
        for (auto [neighbor, weight] : adj[node]) {
            ll new_dist = d + weight;
            if (new_dist < dist[neighbor]) {
                dist[neighbor] = new_dist;
                pq.push({dist[neighbor], neighbor});
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    
    for (int i = 0; i < m; ++i) {
        int u, v, b;
        cin >> u >> v >> b;
        adj[u].push_back({v, b});
        adj[v].push_back({u, b});
    }
    
    dijkstra(1);
    
    for (int i = 2; i <= n; ++i) {
        cout << dist[i] + a[i] << (i < n ? " " : "\n");
    }
    
    return 0;
}