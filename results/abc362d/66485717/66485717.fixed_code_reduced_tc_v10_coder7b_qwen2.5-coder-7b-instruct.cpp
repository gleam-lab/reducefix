#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 2 * 100005;
const ll INF = LLONG_MAX / 2;

vector<pair<int, int>> adj[MAXN];
ll dist[MAXN];

void dijkstra(int start, int n) {
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    fill(dist, dist + n + 1, INF);
    dist[start] = 0;
    pq.push({0, start});
    
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        
        if (d > dist[u]) continue;
        
        for (auto &[v, w] : adj[u]) {
            ll nd = d + w + min(dist[u], dist[v]);
            if (nd < dist[v]) {
                dist[v] = nd;
                pq.push({nd, v});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n, m; cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    
    for (int i = 0; i < m; ++i) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    dijkstra(1, n);
    
    for (int i = 2; i <= n; ++i) {
        cout << dist[i] << " ";
    }
    
    return 0;
}