#include <vector>
#include <iostream>
#include <queue>
#include <climits>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<long long> A(N + 1);
    vector<vector<pair<int, long long>>> G(N + 1);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    for (int i = 0; i < M; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }

    pq.push({0, 1}); // Start from vertex 1 with initial cost 0
    vector<long long> dist(N + 1, LLONG_MAX); // Distance from vertex 1 to vertex i

    while (!pq.empty()) {
        auto [cost, u] = pq.top();
        pq.pop();

        if (dist[u] < cost) continue; // Skip if we've already found a better path

        for (auto &edge : G[u]) {
            int v = edge.first;
            long long edge_cost = edge.second;
            long long new_cost = cost + A[v] + edge_cost;

            if (new_cost < dist[v]) {
                dist[v] = new_cost;
                pq.push({new_cost, v});
            }
        }
    }

    for (int i = 2; i <= N; ++i) {
        cout << (dist[i] < LLONG_MAX ? dist[i] : -1) << " ";
    }

    return 0;
}