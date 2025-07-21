#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1e18

vector<pair<ll, ll>> adj[200005];

ll dijkstra(ll src, ll n) {
    vector<ll> dist(n+1, INF);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    dist[src] = 0;
    pq.push({0, src});
    
    while (!pq.empty()) {
        auto [cost, node] = pq.top();
        pq.pop();
        
        if (dist[node] < cost)
            continue;
        
        for (auto [neighbor, weight] : adj[node]) {
            ll new_cost = cost + weight + adj[neighbor][0].second;
            
            if (new_cost < dist[neighbor]) {
                dist[neighbor] = new_cost;
                pq.push({new_cost, neighbor});
            }
        }
    }
    
    return dist[n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n, m;
    cin >> n >> m;
    
    for (ll i = 1; i <= n; i++) {
        ll a;
        cin >> a;
        adj[i].push_back({a, 0});
    }
    
    for (ll i = 0; i < m; i++) {
        ll u, v, b;
        cin >> u >> v >> b;
        adj[u].push_back({v, b});
        adj[v].push_back({u, b});
    }
    
    for (ll i = 2; i <= n; i++) {
        cout << dijkstra(1, i) << " ";
    }
    
    return 0;
}