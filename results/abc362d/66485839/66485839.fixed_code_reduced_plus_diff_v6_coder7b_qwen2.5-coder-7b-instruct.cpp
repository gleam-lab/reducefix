#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 200010;

vector<pair<ll, int>> adj[MAXN];
ll dist[MAXN];

void dijkstra(int src, int n) {
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({dist[src], src});
    
    while (!pq.empty()) {
        pair<ll, int> top = pq.top();
        pq.pop();
        
        int node = top.second;
        ll cost = top.first;
        
        if (cost > dist[node]) continue;
        
        for (auto &child : adj[node]) {
            int child_node = child.second;
            ll child_cost = child.first;
            
            if (dist[child_node] > cost + child_cost) {
                dist[child_node] = cost + child_cost;
                pq.push({dist[child_node], child_node});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    
    for (int i = 1; i <= n; ++i) {
        cin >> dist[i];
    }
    
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }
    
    for (int i = 1; i <= n; ++i) {
        fill(dist + 1, dist + n + 1, LLONG_MAX);
        dist[i] = 0;
        dijkstra(i, n);
        
        for (int j = 1; j <= n; ++j) {
            if (i != j) cout << dist[j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}