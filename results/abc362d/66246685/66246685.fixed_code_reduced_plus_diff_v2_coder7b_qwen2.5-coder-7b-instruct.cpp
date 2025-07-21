#include <bits/stdc++.h>
using namespace std;

typedef pair<long long, long long> pl;

vector<vector<pl>> adj;
vector<long long> dist;

void dijkstra(long long start) {
    priority_queue<pl, vector<pl>, greater<pl>> pq;
    pq.push({start, 0});
    dist[start] = 0;

    while (!pq.empty()) {
        auto [node, cost] = pq.top(); pq.pop();

        if (cost > dist[node]) continue;

        for (auto &[neighbor, weight] : adj[node]) {
            long long new_cost = cost + weight;
            if (new_cost < dist[neighbor]) {
                dist[neighbor] = new_cost;
                pq.push({neighbor, new_cost});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    long long N, M;
    cin >> N >> M;

    adj.resize(N);
    dist.resize(N, LLONG_MAX);

    for (long long i = 0; i < N; ++i) {
        cin >> adj[i].back().first;
        adj[i].back().second = 0; // No edge weight for vertex itself
    }

    for (long long i = 0; i < M; ++i) {
        long long u, v, b;
        cin >> u >> v >> b;
        --u, --v; // Adjust indices to be zero-based
        adj[u].emplace_back(v, b);
        adj[v].emplace_back(u, b);
    }

    dijkstra(0); // Start from vertex 1

    for (long long i = 1; i < N; ++i) {
        cout << dist[i] + adj[i][0].first << " "; // Add the vertex weight
    }

    return 0;
}