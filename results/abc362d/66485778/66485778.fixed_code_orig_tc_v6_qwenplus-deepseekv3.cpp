#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const i64 INF = 1e18;

void solve() {
    int N, M;
    cin >> N >> M;
    vector<i64> A(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }
    vector<vector<pair<int, i64>>> g(N + 1);
    for (int i = 0; i < M; ++i) {
        int U, V;
        i64 B;
        cin >> U >> V >> B;
        g[U].emplace_back(V, B);
        g[V].emplace_back(U, B);
    }

    vector<i64> dist(N + 1, INF);
    dist[1] = A[1];
    priority_queue<pair<i64, int>, vector<pair<i64, int>>, greater<pair<i64, int>>> pq;
    pq.emplace(dist[1], 1);

    while (!pq.empty()) {
        auto [current_dist, u] = pq.top();
        pq.pop();
        if (current_dist > dist[u]) continue;
        for (auto [v, B] : g[u]) {
            i64 new_dist = current_dist + B + A[v];
            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.emplace(new_dist, v);
            }
        }
    }

    for (int i = 2; i <= N; ++i) {
        cout << dist[i] << " \n"[i == N];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}