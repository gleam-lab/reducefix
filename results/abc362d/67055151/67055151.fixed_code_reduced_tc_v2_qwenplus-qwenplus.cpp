#include <bits/stdc++.h>

using namespace std;

using ll = long long;
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

    vector<vector<pair<ll, ll>>> graph(N);
    for (ll i = 0; i < M; ++i) {
        ll u, v, b;
        cin >> u >> v >> b;
        u--, v--;
        graph[u].emplace_back(v, b);
        graph[v].emplace_back(u, b);
    }

    // dist[i] = minimum path weight from node 0 to node i
    vector<ll> dist(N, INF);
    dist[0] = A[0]; // Include starting node's vertex weight

    // Priority Queue: (current distance, node)
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;
    pq.emplace(dist[0], 0);

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (auto [v, b] : graph[u]) {
            ll new_cost = dist[u] + b + A[v]; // path so far + edge + destination vertex
            if (new_cost < dist[v]) {
                dist[v] = new_cost;
                pq.emplace(dist[v], v);
            }
        }
    }

    // Output result for nodes 2 to N (i.e., indices 1 to N-1)
    for (ll i = 1; i < N; ++i) {
        cout << dist[i] << " ";
    }
    cout << '\n';

    return 0;
}