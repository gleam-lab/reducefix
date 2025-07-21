#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using VL = vector<ll>;
using P = pair<int, int>;
const ll inf = 1000000000;
const ll MOD = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M;
    cin >> N >> M;
    
    vector<ll> A(N), B(M);
    vector<vector<pair<ll, ll>>> G(N);
    vector<ll> dp(N, inf); // dp[i] will store the minimum weight to reach vertex i

    for (ll i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    for (ll i = 0; i < M; ++i) {
        int u, v;
        ll weight;
        cin >> u >> v >> weight;
        --u; --v; // Convert to zero-indexed
        G[u].push_back({v, weight});
        G[v].push_back({u, weight});
    }
    
    dp[0] = A[0]; // Starting from vertex 1
    priority_queue<P, vector<P>, greater<P>> pq; // Min-heap to process vertices
    pq.push({A[0], 0}); // {total weight, vertex index}
    
    while (!pq.empty()) {
        auto [current_weight, u] = pq.top();
        pq.pop();
        
        for (auto &neigh : G[u]) {
            ll v = neigh.first;
            ll edge_weight = neigh.second;
            ll new_weight = current_weight + edge_weight + A[v];
            
            if (new_weight < dp[v]) {
                dp[v] = new_weight;
                pq.push({new_weight, v});
            }
        }
    }
    
    for (ll i = 1; i < N; ++i) {
        cout << dp[i] << " ";
    }
    cout << endl;
    
    return 0;
}