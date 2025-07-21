#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

const int INF = LLONG_MAX;

struct Edge {
    int to, weight;
};

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<Edge>> G(N + 1);
    vector<long long> A(N + 1);
    long long start_weight;

    // Read vertex weights
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    // Initialize edge list
    for (int i = 0; i < M; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }

    // Distance array
    vector<long long> dist(N + 1, INF);
    dist[1] = A[1]; // Start with vertex 1
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    // Priority queue for Dijkstra's algorithm
    pq.push({A[1], 1});

    while (!pq.empty()) {
        auto [w, u] = pq.top();
        pq.pop();

        if (dist[u] < w) continue;

        for (auto &edge : G[u]) {
            int v = edge.to;
            long long next_w = w + A[v] + edge.weight;

            if (next_w < dist[v]) {
                dist[v] = next_w;
                pq.push({next_w, v});
            }
        }
    }

    // Output the minimum weight for each vertex from 2 to N
    for (int i = 2; i <= N; ++i) {
        cout << dist[i] << " ";
    }
    cout << "\n";

    return 0;
}