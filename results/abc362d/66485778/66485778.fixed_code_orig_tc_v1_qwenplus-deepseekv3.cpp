#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const i64 INF = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<i64> A(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    vector<vector<pair<int, i64>>> g(N + 1);
    for (int i = 0; i < M; ++i) {
        int u, v;
        i64 b;
        cin >> u >> v >> b;
        g[u].emplace_back(v, b + A[v]);
        g[v].emplace_back(u, b + A[u]);
    }

    vector<i64> dist(N + 1, INF);
    dist[1] = A[1];
    priority_queue<pair<i64, int>, vector<pair<i64, int>>, greater<pair<i64, int>>> pq;
    pq.emplace(dist[1], 1);

    while (!pq.empty()) {
        auto [current_dist, u] = pq.top();
        pq.pop();
        if (current_dist > dist[u]) continue;
        for (auto [v, weight] : g[u]) {
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.emplace(dist[v], v);
            }
        }
    }

    for (int i = 2; i <= N; ++i) {
        cout << dist[i] << " \n"[i == N];
    }

    return 0;
}