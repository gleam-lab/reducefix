#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

typedef pair<int, long long> pii;

long long dijkstra(const vector<vector<pii>>& graph, int start) {
    int n = graph.size();
    vector<long long> dist(n, numeric_limits<long long>::max());
    dist[start] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({start, 0});

    while (!pq.empty()) {
        auto [current, d] = pq.top();
        pq.pop();

        if (d > dist[current])
            continue;

        for (auto [neighbor, weight] : graph[current]) {
            long long new_dist = d + weight;
            if (new_dist < dist[neighbor]) {
                dist[neighbor] = new_dist;
                pq.push({neighbor, new_dist});
            }
        }
    }

    return dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<pii>> graph(n);
    vector<int> weights(n);

    for (int i = 0; i < n; ++i) {
        cin >> weights[i];
    }

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v; // Adjusting for 0-based indexing
        graph[u].emplace_back(v, weights[v] + w);
        graph[v].emplace_back(u, weights[u] + w);
    }

    vector<long long> result = dijkstra(graph, 0);

    for (int i = 1; i < n; ++i) {
        cout << result[i] + weights[i] << " ";
    }
    cout << endl;

    return 0;
}