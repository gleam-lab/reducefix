#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1e18

const int MAXN = 2e5 + 7;
vector<pair<ll, ll>> adj[MAXN];

void dijkstra(int n, int start, vector<ll>& dist) {
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({dist[start], start});
    
    while (!pq.empty()) {
        auto [cost, u] = pq.top();
        pq.pop();
        
        if (cost > dist[u]) continue;
        
        for (auto [v, weight] : adj[u]) {
            ll new_cost = cost + weight;
            if (new_cost < dist[v]) {
                dist[v] = new_cost;
                pq.push({new_cost, v});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    vector<ll> a(n + 1), dist(n + 1, INF);
    
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) {
        int u, v, b;
        cin >> u >> v >> b;
        adj[u].push_back({v, b});
        adj[v].push_back({u, b});
    }
    
    dist[1] = a[1];
    for (int i = 2; i <= n; i++) {
        dijkstra(n, i, dist);
        cout << dist[i] << " ";
    }
    
    return 0;
}