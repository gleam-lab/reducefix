#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF = LLONG_MAX;

int main() {
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
        G[u].emplace_back(v, b);
        G[v].emplace_back(u, b);
    }
    
    vector<ll> dist(N, INF);
    dist[0] = A[0];
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.emplace(dist[0], 0);
    
    while (!pq.empty()) {
        auto [current_dist, u] = pq.top();
        pq.pop();
        
        if (current_dist > dist[u]) continue;
        
        for (auto [v, b] : G[u]) {
            ll new_dist = current_dist + b + A[v];
            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.emplace(new_dist, v);
            }
        }
    }
    
    for (int i = 1; i < N; ++i) {
        cout << dist[i] << " ";
    }
    cout << endl;
    
    return 0;
}