#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

using ll = long long;

const int INF = 1e18;

struct Edge {
    int to;
    ll weight;
};

void dijkstra(const vector<vector<Edge>>& graph, int start, vector<ll>& dist) {
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, start});

    dist.assign(graph.size(), INF);
    dist[start] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        ll d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue;

        for (const auto& [v, weight] : graph[u]) {
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<Edge>> graph(N);
    vector<ll> vertex_weights(N);
    vector<int> edges_to_process;

    for (int i = 0; i < N; ++i) {
        cin >> vertex_weights[i];
    }

    for (int i = 0; i < M; ++i) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        graph[u - 1].push_back({v - 1, w});
        graph[v - 1].push_back({u - 1, w});
        edges_to_process.push_back(i);
    }

    vector<ll> dist(N);
    dijkstra(graph, 0, dist);

    for (int i = 1; i < N; ++i) {
        cout << dist[i] + vertex_weights[i] << " ";
    }
    cout << endl;

    return 0;
}