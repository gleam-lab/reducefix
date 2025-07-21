#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using VL = vector<ll>;
using P = pair<ll, ll>;

const ll INF = 1e18;

int main() {
    ios_base::sync_with_stdio(false);
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

    priority_queue<P, vector<P>, greater<P>> pq;
    vector<ll> dist(N, INF);
    dist[0] = A[0]; // Start node includes its own vertex weight
    pq.emplace(dist[0], 0);

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u]) continue;

        for (auto [v, cost] : G[u]) {
            ll new_cost = d + cost + A[v]; // Add edge and destination vertex weights
            if (new_cost < dist[v]) {
                dist[v] = new_cost;
                pq.emplace(dist[v], v);
            }
        }
    }

    for (ll i = 1; i < N; ++i) {
        cout << dist[i] << " ";
    }
    cout << "\n";

    return 0;
}