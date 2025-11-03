#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll inf = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll N, M;
    cin >> N >> M;
    
    vector<ll> A(N);
    vector<vector<pair<ll, ll>>> G(N);
    
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    for (int i = 0; i < M; i++) {
        ll u, v, b;
        cin >> u >> v >> b;
        u--; v--;
        G[u].push_back({v, b});
        G[v].push_back({u, b});
    }
    
    vector<ll> ans(N, inf);
    priority_queue<P, vector<P>, greater<P>> pq;
    
    ans[0] = A[0];
    pq.push({A[0], 0});
    
    while (!pq.empty()) {
        auto [cost, u] = pq.top();
        pq.pop();
        
        if (cost > ans[u]) continue;
        
        for (auto [v, edge_weight] : G[u]) {
            ll new_cost = cost + edge_weight + A[v];
            if (new_cost < ans[v]) {
                ans[v] = new_cost;
                pq.push({new_cost, v});
            }
        }
    }
    
    for (int i = 1; i < N; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    
    return 0;
}