#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 10;
const ll INF = 1e18;

vector<pll> adj[MAXN];

ll dijkstra(int src, int dest, int n) {
    vector<ll> dist(n + 1, INF);
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    
    dist[src] = 0;
    pq.push({dist[src], src});
    
    while (!pq.empty()) {
        auto [currentDist, u] = pq.top();
        pq.pop();
        
        if (u == dest) break;
        
        if (currentDist > dist[u]) continue;
        
        for (auto [v, weight] : adj[u]) {
            ll newDist = currentDist + weight + (v == dest ? 0 : 0);
            if (newDist < dist[v]) {
                dist[v] = newDist;
                pq.push({dist[v], v});
            }
        }
    }
    
    return dist[dest];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    
    for (int i = 0; i < m; ++i) {
        int u, v, b;
        cin >> u >> v >> b;
        adj[u].push_back({v, b});
        adj[v].push_back({u, b});
    }
    
    for (int i = 2; i <= n; ++i) {
        cout << dijkstra(1, i, n) << " ";
    }
    cout << "\n";
    
    return 0;
}