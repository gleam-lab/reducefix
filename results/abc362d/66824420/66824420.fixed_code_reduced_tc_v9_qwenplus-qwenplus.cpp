#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<long long> A(n + 1); // Use long long to avoid overflow
    for(int i = 1; i <= n; ++i) {
        cin >> A[i];
    }

    vector<vector<pair<int, long long>>> adj(n + 1);
    for(int j = 0; j < m; ++j) {
        int u, v;
        long long b;
        cin >> u >> v >> b;
        adj[u].push_back({v, b});
        adj[v].push_back({u, b});
    }

    vector<long long> dist(n + 1, numeric_limits<long long>::max());
    dist[1] = A[1]; // Initial cost is just the weight of vertex 1

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    pq.push({dist[1], 1});

    while(!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if(d > dist[u]) continue;

        for(auto [v, b] : adj[u]) {
            long long new_dist = d + b + A[v];

            if(new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.push({new_dist, v});
            }
        }
    }

    for(int i = 2; i <= n; ++i) {
        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}