#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

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

    vector<vector<P>> G(N);
    for (ll i = 0; i < M; ++i) {
        ll u, v, b;
        cin >> u >> v >> b;
        u--;
        v--;
        G[u].emplace_back(v, b);
        G[v].emplace_back(u, b);
    }

    vector<ll> dist(N, INF);
    priority_queue<P, vector<P>, greater<>> pq;

    // Start from node 0 with initial cost A[0]
    dist[0] = A[0];
    pq.emplace(dist[0], 0);

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (auto [v, b] : G[u]) {
            ll new_cost = d + b + A[v];
            if (new_cost < dist[v]) {
                dist[v] = new_cost;
                pq.emplace(dist[v], v);
            }
        }
    }

    for (ll i = 1; i < N; ++i) {
        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}