#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using VL = vector<ll>;
using P = pair<int, int>;
const ll inf = 1e18;

void dijkstra(vector<vector<pair<int, int>>>& G, const vector<ll>& A, int start, vector<ll>& dist) {
    priority_queue<P, vector<P>, greater<>> pq;
    dist[start] = A[start];
    pq.push(P(dist[start], start));

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();

        if (dist[u] < d) continue;

        for (auto [v, w] : G[u]) {
            ll nd = d + A[v] + w;
            if (nd < dist[v]) {
                dist[v] = nd;
                pq.push(P(nd, v));
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    ll N, M;
    cin >> N >> M;

    vector<ll> A(N), B(M);
    vector<vector<pair<int, int>>> G(N);

    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v >> B[i];
        --u, --v; // Adjust indices to zero-based
        G[u].emplace_back(v, B[i]);
        G[v].emplace_back(u, B[i]);
    }

    vector<ll> dist(N, inf);
    dijkstra(G, A, 0, dist);

    for (int i = 1; i < N; ++i) {
        cout << dist[i] << " ";
    }

    return 0;
}