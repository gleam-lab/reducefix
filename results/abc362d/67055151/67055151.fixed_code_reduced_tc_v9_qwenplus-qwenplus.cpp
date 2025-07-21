#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll INF = 5LL << 60;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;

    vector<ll> A(n);
    for (ll i = 0; i < n; ++i) {
        cin >> A[i];
    }

    vector<vector<pair<ll, ll>>> graph(n);
    for (ll i = 0; i < m; ++i) {
        ll u, v, b;
        cin >> u >> v >> b;
        u--; v--;
        graph[u].push_back({v, b});
        graph[v].push_back({u, b});
    }

    vector<ll> dist(n, INF);
    dist[0] = A[0]; // Starting at node 0 with its own weight

    using pii = pair<ll, ll>; // (total cost, node)
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({dist[0], 0});

    while (!pq.empty()) {
        auto [cost, u] = pq.top(); pq.pop();
        if (cost > dist[u]) continue;

        for (auto [v, b] : graph[u]) {
            ll new_cost = cost + b + A[v]; // Cost to reach v via u
            if (new_cost < dist[v]) {
                dist[v] = new_cost;
                pq.push({new_cost, v});
            }
        }
    }

    // Output results for nodes 2 to N
    for (ll i = 1; i < n; ++i) {
        cout << dist[i] << " ";
    }
    cout << '\n';

    return 0;
}