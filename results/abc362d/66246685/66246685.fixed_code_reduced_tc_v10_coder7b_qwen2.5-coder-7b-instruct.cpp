#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

struct Edge {
    int to;
    long long cost;
};

vector<long long> dijkstra(int start, const vector<vector<Edge>>& graph, const vector<long long>& weights) {
    int n = graph.size();
    vector<long long> dist(n, INF);
    dist[start] = weights[start];
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    pq.push({dist[start], start});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (auto& e : graph[u]) {
            int v = e.to;
            long long cost = e.cost + weights[v];

            if (cost < dist[v]) {
                dist[v] = cost;
                pq.push({cost, v});
            }
        }
    }

    return dist;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<long long> weights(n);
    for (int i = 0; i < n; ++i) cin >> weights[i];

    vector<vector<Edge>> graph(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }

    vector<long long> result;
    result.reserve(n - 1);

    for (int i = 1; i < n; ++i) {
        auto dist = dijkstra(0, graph, weights);
        result.push_back(dist[i]);
    }

    for (long long r : result) cout << r << " ";

    return 0;
}