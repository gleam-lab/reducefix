#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<vector<pair<int, long long>>> adj(N + 1); // 1-based indexing
    for (int i = 0; i < M; ++i) {
        int U, V;
        long long B;
        cin >> U >> V >> B;
        adj[U].emplace_back(V, B);
        adj[V].emplace_back(U, B);
    }

    // Initialize distances: dist[i] is the minimum path weight from node 1 to node i
    vector<long long> dist(N + 1, numeric_limits<long long>::max());
    dist[1] = A[0]; // Start with vertex 1's weight

    // Min-heap priority queue for Dijkstra's algorithm
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    pq.emplace(A[0], 1); // (cost, node)

    while (!pq.empty()) {
        auto [curr_cost, u] = pq.top();
        pq.pop();

        // Early exit if we already found a better path
        if (curr_cost > dist[u]) continue;

        for (const auto& [v, edge_cost] : adj[u]) {
            long long new_cost = curr_cost + edge_cost + A[v - 1];

            if (new_cost < dist[v]) {
                dist[v] = new_cost;
                pq.emplace(new_cost, v);
            }
        }
    }

    // Output results for nodes 2 through N
    for (int i = 2; i <= N; ++i) {
        cout << dist[i] << " ";
    }
    cout << "\n";

    return 0;
}