#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<long long, int> PII;

int main() {
    int n, m;
    cin >> n >> m;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<vector<PII>> adj(n + 1);
    for (int j = 0; j < m; ++j) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    vector<long long> dist(n + 1, LLONG_MAX);
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    
    dist[1] = a[0];
    pq.emplace(a[0], 1);

    while (!pq.empty()) {
        auto [val, node] = pq.top(); pq.pop();

        if (val > dist[node]) continue;

        for (auto [neighbor, weight] : adj[node]) {
            long long new_dist = val + weight + a[neighbor - 1];
            if (new_dist < dist[neighbor]) {
                dist[neighbor] = new_dist;
                pq.emplace(new_dist, neighbor);
            }
        }
    }

    for (int i = 2; i <= n; ++i) {
        cout << dist[i] << " ";
    }

    return 0;
}