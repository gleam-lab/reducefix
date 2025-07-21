#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>

using namespace std;

struct Edge {
    int to;
    long long weight;
};

vector<long long> dijkstra(const vector<vector<Edge>>& graph, int start, const vector<long long>& node_weights) {
    int n = graph.size();
    vector<long long> dist(n, LLONG_MAX);
    dist[start] = 0;

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();

        if (d > dist[u]) continue;

        for (auto [v, w] : graph[u]) {
            long long new_dist = d + w + node_weights[v];

            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.push({new_dist, v});
            }
        }
    }

    return dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<long long> node_weights(n);
    for (int i = 0; i < n; ++i) cin >> node_weights[i];

    vector<vector<Edge>> graph(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }

    vector<long long> result;
    for (int i = 1; i < n; ++i) {
        auto distances = dijkstra(graph, 0, node_weights);
        result.emplace_back(distances[i]);
    }

    for (long long dist : result) {
        cout << dist << " ";
    }
    cout << endl;

    return 0;
}