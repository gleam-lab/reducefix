#include <bits/stdc++.h>
using namespace std;
#define int long long

int N, M;
vector<int> A;
vector<vector<pair<int, int>>> G; // Adjacency list
vector<int> dist; // Minimum distance to each vertex
vector<bool> vis; // Visited vertices

void solve() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1}); // Start from vertex 1 with distance 0
    dist[1] = A[1];

    while (!pq.empty()) {
        int d = pq.top().first;
        int v = pq.top().second;
        pq.pop();

        if (vis[v]) continue;
        vis[v] = true;

        for (auto& [next_v, weight] : G[v]) {
            if (dist[next_v] > dist[v] + weight + A[next_v]) { // Total weight = distance to v + weight of edge + weight of vertex
                dist[next_v] = dist[v] + weight + A[next_v];
                pq.push({dist[next_v], next_v});
            }
        }
    }
}

int main() {
    cin >> N >> M;
    A.resize(N + 1);
    G.resize(N + 1);
    vis.resize(N + 1, false);
    dist.resize(N + 1, (int)1e18); // Initialize distances with a large number

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    for (int i = 1; i <= M; i++) {
        int u, v, b;
        cin >> u >> v >> b;
        G[u].push_back({v, b});
        G[v].push_back({u, b});
    }

    solve();

    for (int i = 2; i <= N; i++) {
        cout << (dist[i] < (int)1e18 ? dist[i] : 0) << (i < N ? " " : "\n"); // To handle the case when a vertex is not reachable
    }

    return 0;
}