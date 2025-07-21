#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const long long INF = 1LL << 60; // A very large number to represent infinity

struct Edge {
    int to;
    long long weight;
};

vector<long long> dijkstra(const vector<vector<Edge>>& graph, int start, const vector<long long>& vertexWeights) {
    int n = graph.size();
    vector<long long> dist(n, INF);
    dist[start] = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (auto [v, w] : graph[u]) {
            long long newDist = d + w + vertexWeights[v];
            if (newDist < dist[v]) {
                dist[v] = newDist;
                pq.push({newDist, v});
            }
        }
    }

    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<long long> vertexWeights(n);
    for (long long& val : vertexWeights) cin >> val;

    vector<vector<Edge>> graph(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v; // Adjust indices to be zero-based
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }

    vector<long long> results;
    for (int i = 1; i < n; ++i) {
        vector<long long> dist = dijkstra(graph, 0, vertexWeights);
        results.emplace_back(dist[i] + vertexWeights[i]);
    }

    for (long long result : results) {
        cout << result << " ";
    }
    cout << endl;

    return 0;
}