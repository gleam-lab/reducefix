#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    vector<vector<pair<int, ll>>> adj(n + 1);
    for (int j = 0; j < m; ++j) {
        int u, v;
        ll b;
        cin >> u >> v >> b;
        adj[u].emplace_back(v, b);
        adj[v].emplace_back(u, b);
    }
    
    vector<ll> dist(n + 1, LLONG_MAX);
    dist[1] = a[0];
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.emplace(a[0], 1);
    
    while (!pq.empty()) {
        auto [current_dist, u] = pq.top();
        pq.pop();
        
        if (current_dist > dist[u]) {
            continue;
        }
        
        for (auto [v, b] : adj[u]) {
            ll new_dist = current_dist + b + a[v - 1];
            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.emplace(new_dist, v);
            }
        }
    }
    
    for (int i = 2; i <= n; ++i) {
        cout << (dist[i] == LLONG_MAX ? -1 : dist[i]) << " ";
    }
    
    return 0;
}