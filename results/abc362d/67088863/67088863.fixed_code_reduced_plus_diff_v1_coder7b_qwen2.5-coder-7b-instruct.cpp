#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Edge {
    int to, weight;
};

const int MAXN = 200005;
const int INF = INT_MAX;

void dijkstra(const vector<vector<Edge>>& graph, const vector<int>& weights, int start, vector<long long>& dist) {
    int n = graph.size();
    dist[start] = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [currentDist, u] = pq.top();
        pq.pop();

        if (currentDist > dist[u]) continue;

        for (const auto& edge : graph[u]) {
            int v = edge.to;
            long long newDist = currentDist + edge.weight + weights[v];

            if (newDist < dist[v]) {
                dist[v] = newDist;
                pq.push({newDist, v});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> weights(n);
    for (int i = 0; i < n; ++i) {
        cin >> weights[i];
    }

    vector<vector<Edge>> graph(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v; // Convert to zero-based indexing
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    vector<long long> dist(n, INF);
    dijkstra(graph, weights, 0, dist);

    for (int i = 1; i < n; ++i) {
        cout << dist[i] + weights[i] << " ";
    }
    cout << endl;

    return 0;
}