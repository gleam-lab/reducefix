#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using VL = vector<ll>;
using P = pair<ll, int>; // Changed first type to ll for cost
const ll INF = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M;
    cin >> N >> M;

    vector<ll> A(N);
    for (ll i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<vector<pair<ll, ll>>> G(N); // Each edge stores (to, weight)
    for (ll i = 0; i < M; ++i) {
        ll u, v, b;
        cin >> u >> v >> b;
        u--;
        v--;
        G[u].push_back({v, b});
        G[v].push_back({u, b});
    }

    priority_queue<P, vector<P>, greater<>> pq;
    vector<ll> dist(N, INF);
    dist[0] = A[0]; // Start node includes its own vertex weight
    pq.push({A[0], 0});

    while (!pq.empty()) {
        auto [cost, u] = pq.top();
        pq.pop();

        if (cost > dist[u]) continue;

        for (auto [v, b] : G[u]) {
            ll new_cost = cost + b + A[v]; // Path cost: current cost + edge + destination vertex weight
            if (new_cost < dist[v]) {
                dist[v] = new_cost;
                pq.push({new_cost, v});
            }
        }
    }

    for (ll i = 1; i < N; ++i) {
        cout << dist[i] << " ";
    }
    cout << "\n";

    return 0;
}