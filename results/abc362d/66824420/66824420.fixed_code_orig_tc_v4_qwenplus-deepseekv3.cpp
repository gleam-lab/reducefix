#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    cin >> N >> M;
    vector<ll> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    
    vector<vector<pair<int, ll>>> adj(N+1);
    for (int j = 0; j < M; ++j) {
        int u, v;
        ll b;
        cin >> u >> v >> b;
        adj[u].emplace_back(v, b);
        adj[v].emplace_back(u, b);
    }
    
    vector<ll> dist(N+1, LLONG_MAX);
    dist[1] = A[0];
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.emplace(dist[1], 1);
    
    while (!pq.empty()) {
        auto [d_u, u] = pq.top();
        pq.pop();
        
        if (d_u > dist[u]) continue;
        
        for (auto [v, b] : adj[u]) {
            ll new_dist = d_u + b + A[v-1];
            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.emplace(new_dist, v);
            }
        }
    }
    
    for (int i = 2; i <= N; ++i) {
        cout << dist[i] << " \n"[i == N];
    }
    
    return 0;
}