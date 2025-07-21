#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    long long A[N];
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<vector<pair<int, long long>>> adj(N + 1); // adj[0] unused
    for (int j = 0; j < M; ++j) {
        int u, v;
        long long b;
        cin >> u >> v >> b;
        adj[u].push_back({v, b});
        adj[v].push_back({u, b});
    }

    vector<long long> dist(N + 1, 1e18);
    dist[1] = A[0]; // Start from vertex 1

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    pq.push({dist[1], 1});

    while (!pq.empty()) {
        auto [currentDist, u] = pq.top();
        pq.pop();

        if (currentDist > dist[u]) continue;

        for (auto& [v, edgeWeight] : adj[u]) {
            long long newDist = currentDist + edgeWeight + A[v - 1];
            if (newDist < dist[v]) {
                dist[v] = newDist;
                pq.push({newDist, v});
            }
        }
    }

    for (int i = 2; i <= N; ++i) {
        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}