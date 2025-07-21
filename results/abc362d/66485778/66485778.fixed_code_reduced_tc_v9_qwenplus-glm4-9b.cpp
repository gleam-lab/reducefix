#include <bits/stdc++.h>
using namespace std;
#define int long long

int N, M;
vector<pair<int, int>> g[N]; // Adjacency list for the graph
vector<long long> d(N + 1, LLONG_MAX); // Distance array
vector<long long> a(N + 1); // Vertex weights

void solve() {
    // Input reading part
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= M; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        g[u].push_back({v, c});
        g[v].push_back({u, c});
    }

    // Priority queue for Dijkstra's algorithm
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    // Initialize the distance to the starting vertex 1 as the weight of vertex 1
    d[1] = a[1];
    pq.push({a[1], 1});

    // Dijkstra's algorithm to find the shortest path from vertex 1 to all other vertices
    while (!pq.empty()) {
        auto [dist, u] = pq.top();
        pq.pop();

        // If we have already visited this vertex, continue to the next one
        if (d[u] < dist) continue;

        // Process all adjacent vertices
        for (auto& [v, weight] : g[u]) {
            long long newDist = dist + weight + a[v];
            // If a shorter path to v is found, update the distance and push it to the queue
            if (d[v] > newDist) {
                d[v] = newDist;
                pq.push({newDist, v});
            }
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    // Read and process each test case
    int t = 1;
    while (t--) {
        solve();
        for (int i = 2; i <= N; ++i) {
            cout << d[i] << (i < N ? " " : "");
        }
        cout << endl;
    }

    return 0;
}