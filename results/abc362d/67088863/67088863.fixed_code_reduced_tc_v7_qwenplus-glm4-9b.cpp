#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

const int N = 200005;
vector<pair<int, long long>> adj[N];
long long dist[N];

void dijkstra(int start, int n) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, start});
    fill(dist, dist + n, numeric_limits<long long>::max());
    dist[start] = 0;

    while (!pq.empty()) {
        auto [weight, node] = pq.top();
        pq.pop();
        if (weight > dist[node]) continue;

        for (auto [neighbor, edge_weight] : adj[node]) {
            if (dist[neighbor] > weight + edge_weight) {
                dist[neighbor] = weight + edge_weight;
                pq.push({dist[neighbor], neighbor});
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    long long start_vertex_value;
    cin >> start_vertex_value;

    for (int i = 0; i < n; ++i) {
        long long vertex_value;
        cin >> vertex_value;
        adj[i].emplace_back(i, vertex_value);
    }

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u;
        --v;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    dijkstra(0, n);

    for (int i = 1; i < n; ++i) {
        cout << dist[i] + (adj[i].front()).second << " ";
    }
    cout << endl;

    return 0;
}