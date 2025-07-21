#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF = 1LL << 60;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M;
    cin >> N >> M;
    
    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    vector<vector<P>> G(N);
    for (int i = 0; i < M; ++i) {
        ll u, v, b;
        cin >> u >> v >> b;
        u--; v--;
        G[u].emplace_back(v, b + A[v]);
        G[v].emplace_back(u, b + A[u]);
    }
    
    vector<ll> dist(N, INF);
    dist[0] = A[0];
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.emplace(dist[0], 0);
    
    while (!pq.empty()) {
        auto [current_dist, u] = pq.top();
        pq.pop();
        
        if (current_dist > dist[u]) continue;
        
        for (auto [v, cost] : G[u]) {
            if (dist[v] > dist[u] + cost) {
                dist[v] = dist[u] + cost;
                pq.emplace(dist[v], v);
            }
        }
    }
    
    for (int i = 1; i < N; ++i) {
        cout << dist[i] << (i == N - 1 ? "\n" : " ");
    }
    
    return 0;
}