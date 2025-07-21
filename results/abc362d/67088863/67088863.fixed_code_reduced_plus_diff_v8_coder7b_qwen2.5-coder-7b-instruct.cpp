#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const long long INF = numeric_limits<long long>::max();

void dijkstra(const vector<vector<pair<int, long long>>>& adj, const vector<long long>& val, vector<long long>& dist, int start) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u])
            continue;

        for (auto [v, w] : adj[u]) {
            long long new_dist = d + w + val[v];
            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.push({new_dist, v});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<long long> val(n);
    for (long long& v : val)
        cin >> v;

    vector<vector<pair<int, long long>>> adj(n);

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v; // Adjust indices to be zero-based
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    vector<long long> dist(n, INF);

    dijkstra(adj, val, dist, 0);

    for (int i = 1; i < n; ++i)
        cout << dist[i] + val[i] << " ";

    return 0;
}