#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pll = pair<ll, ll>;

constexpr ll INF = 5LL << 60;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M;
    cin >> N >> M;
    
    vector<ll> A(N);
    for (ll i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<vector<pll>> graph(N);
    for (ll i = 0; i < M; ++i) {
        ll u, v, b;
        cin >> u >> v >> b;
        u--; v--;
        graph[u].push_back({v, b});
        graph[v].push_back({u, b});
    }

    vector<ll> dist(N, INF);
    dist[0] = A[0]; // Include starting node's value

    priority_queue<pll, vector<pll>, greater<pll>> heap;
    heap.push({dist[0], 0});

    while (!heap.empty()) {
        auto [d, u] = heap.top();
        heap.pop();

        if (d > dist[u]) continue;

        for (auto [v, w] : graph[u]) {
            ll new_cost = d + w + A[v]; // current path cost + edge weight + target vertex weight
            if (new_cost < dist[v]) {
                dist[v] = new_cost;
                heap.push({dist[v], v});
            }
        }
    }

    for (ll i = 1; i < N; ++i) {
        cout << dist[i] << " ";
    }
    cout << "\n";

    return 0;
}