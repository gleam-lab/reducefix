#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1LL << 60;

struct Edge {
    ll to, cost;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M;
    cin >> N >> M;
    vector<ll> A(N);
    for (ll i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<vector<Edge>> graph(N);
    for (ll i = 0; i < M; ++i) {
        ll u, v, b;
        cin >> u >> v >> b;
        u--, v--;
        graph[u].push_back({v, b});
        graph[v].push_back({u, b});
    }

    // Dijkstra's algorithm
    vector<ll> dist(N, INF);
    dist[0] = A[0]; // Start from node 0 with its weight

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;
    pq.push({dist[0], 0});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (auto [v, b] : graph[u]) {
            ll new_dist = dist[u] + b + A[v];
            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.push({dist[v], v});
            }
        }
    }

    // Output the results for nodes 2 to N
    for (ll i = 1; i < N; ++i) {
        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}