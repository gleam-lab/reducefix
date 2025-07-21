#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using VL = vector<ll>;
using P = pair<int, int>;
const ll inf = 1000000000;

void dijkstra(const vector<VL>& graph, const VL& weights, int start, VL& dist) {
    int n = graph.size();
    dist.assign(n, inf);
    dist[start] = 0;

    priority_queue<P, vector<P>, greater<>> pq;
    pq.emplace(dist[start], start);

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();

        if (d > dist[u]) continue;

        for (auto [v, w] : graph[u]) {
            if (dist[v] > dist[u] + w + weights[v]) {
                dist[v] = dist[u] + w + weights[v];
                pq.emplace(dist[v], v);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M;
    cin >> N >> M;

    vector<ll> A(N);
    vector<vector<pair<ll, ll>>> G(N);

    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    for (int i = 0; i < M; ++i) {
        int u, v;
        ll b;
        cin >> u >> v >> b;
        --u; --v;
        G[u].emplace_back(v, b);
        G[v].emplace_back(u, b);
    }

    VL dist(N);
    dijkstra(G, A, 0, dist);

    for (int i = 1; i < N; ++i) {
        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}