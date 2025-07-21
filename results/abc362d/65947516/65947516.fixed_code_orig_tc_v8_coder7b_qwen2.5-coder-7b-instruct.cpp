#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<long long, int> pii;

struct Compare {
    bool operator()(const pii &a, const pii &b) {
        return a.first > b.first;
    }
};

vector<vector<pii>> adj;
vector<long long> dist;
vector<bool> visited;

void dijkstra(int start) {
    priority_queue<pii, vector<pii>, Compare> pq;
    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty()) {
        auto [currentDist, u] = pq.top();
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (auto &[v, w] : adj[u]) {
            if (!visited[v] && currentDist + w + dist[u] < dist[v]) {
                dist[v] = currentDist + w + dist[u];
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    dist.assign(n + 1, LLONG_MAX);
    visited.assign(n + 1, false);

    for (int i = 1; i <= n; ++i) {
        cin >> dist[i];
    }

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w); // Since the graph is undirected
    }

    dijkstra(1);

    for (int i = 2; i <= n; ++i) {
        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}