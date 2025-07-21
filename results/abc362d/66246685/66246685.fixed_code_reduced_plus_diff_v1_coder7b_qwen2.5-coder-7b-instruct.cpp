#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using VL = vector<ll>;
using P = pair<int, int>;

const ll inf = 1e18;

void dijkstra(const vector<VL>& adj, const vector<VL>& cost, VL& dist, int start) {
    int n = adj.size();
    dist.assign(n, inf);
    dist[start] = 0;

    priority_queue<P, vector<P>, greater<>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();

        if (d > dist[u]) continue;

        for (auto [v, w] : zip(adj[u], cost[u])) {
            if (dist[v] > dist[u] + d + w) {
                dist[v] = dist[u] + d + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    ll N, M;
    cin >> N >> M;

    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<vector<ll>> adj(N);
    vector<vector<ll>> cost(N);

    for (int i = 0; i < M; ++i) {
        int u, v, b;
        cin >> u >> v >> b;
        --u, --v; // Convert to zero-based index
        adj[u].push_back(v);
        adj[v].push_back(u);
        cost[u].push_back(b);
        cost[v].push_back(b);
    }

    VL dist(N);
    dijkstra(adj, cost, dist, 0);

    for (int i = 1; i < N; ++i) {
        cout << dist[i] + A[i] << " ";
    }
    cout << endl;

    return 0;
}