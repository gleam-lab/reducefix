#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 9223372036854775807;

template<typename T>
struct Dijkstra {
    using P = pair<T, int>;
    int n;
    vector<vector<P>> G;
    vector<T> dist;

    Dijkstra(int n) : n(n), G(n + 1), dist(n + 1, INF) {}

    void add_edge(int u, int v, T w) {
        G[u].push_back({v, w});
        G[v].push_back({u, w}); // remove this line if graph is directed
    }

    void run(int s) {
        priority_queue<P, vector<P>, greater<P>> pq;
        dist[s] = 0;
        pq.push({0, s});

        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (dist[u] < d) continue;
            for (auto [v, w] : G[u]) {
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, M;
    cin >> N >> M;

    vector<int> A(N + 1);
    for (int i = 1; i <= N; ++i) cin >> A[i];

    Dijkstra<int> dk(N);

    for (int i = 0; i < M; ++i) {
        int u, v, b;
        cin >> u >> v >> b;
        dk.G[u].push_back({v, b + A[v]});
        dk.G[v].push_back({u, b + A[u]});
    }

    dk.dist[1] = A[1];  // include starting vertex weight
    dk.run(1);

    for (int i = 2; i <= N; ++i) {
        cout << dk.dist[i] << " ";
    }
    cout << '\n';

    return 0;
}