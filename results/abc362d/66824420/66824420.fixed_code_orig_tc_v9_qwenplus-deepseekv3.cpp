#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<long long> A(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }
    vector<vector<pair<int, long long>>> adj(N + 1);
    for (int j = 0; j < M; ++j) {
        int U, V;
        long long B;
        cin >> U >> V >> B;
        adj[U].emplace_back(V, B);
        adj[V].emplace_back(U, B);
    }

    vector<long long> dist(N + 1, LLONG_MAX);
    dist[1] = A[1];
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.emplace(dist[1], 1);

    while (!pq.empty()) {
        auto [current_dist, u] = pq.top();
        pq.pop();
        if (current_dist > dist[u]) continue;
        for (auto [v, weight] : adj[u]) {
            long long new_dist = current_dist + weight + A[v];
            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.emplace(new_dist, v);
            }
        }
    }

    for (int i = 2; i <= N; ++i) {
        cout << dist[i] << " \n"[i == N];
    }

    return 0;
}