#include<bits/stdc++.h>
using namespace std;

#define ll long long

vector<vector<pair<ll, ll>>> adjList;
vector<ll> dist;
const ll INF = 1e18;

void dijkstra(ll src) {
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({src, 0});
    
    while (!pq.empty()) {
        auto [node, d] = pq.top();
        pq.pop();
        
        if (d > dist[node]) continue;
        
        for (auto &[neighbor, weight] : adjList[node]) {
            ll newDist = d + weight;
            
            if (newDist < dist[neighbor]) {
                dist[neighbor] = newDist;
                pq.push({neighbor, newDist});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll n, m;
    cin >> n >> m;
    
    adjList.resize(n + 1);
    dist.assign(n + 1, INF);
    
    for (ll i = 1; i <= n; ++i) {
        cin >> dist[i];
    }
    
    for (ll i = 0; i < m; ++i) {
        ll u, v, w;
        cin >> u >> v >> w;
        adjList[u].emplace_back(v, w);
        adjList[v].emplace_back(u, w); // Since the graph is undirected
    }
    
    dist[1] = 0; // Starting point
    
    dijkstra(1);
    
    for (ll i = 2; i <= n; ++i) {
        cout << min(dist[i], dist[i] + dist[1]) << " ";
    }
    
    return 0;
}