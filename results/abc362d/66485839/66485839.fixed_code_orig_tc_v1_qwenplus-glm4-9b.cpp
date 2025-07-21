#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <tuple>

using namespace std;

struct Edge {
    int to, weight;
};

const int MAX_N = 200000 + 10;
vector<Edge> graph[MAX_N];
long long vertex_weights[MAX_N];

void add_edge(int u, int v, int weight) {
    graph[u].push_back({v, weight});
    graph[v].push_back({u, weight});
}

long long dijkstra(int start_vertex) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    vector<long long> min_distance(MAX_N, numeric_limits<long long>::max());

    pq.push({vertex_weights[start_vertex], start_vertex});
    min_distance[start_vertex] = vertex_weights[start_vertex];

    while (!pq.empty()) {
        auto [curr_weight, u] = pq.top();
        pq.pop();

        if (curr_weight > min_distance[u]) continue;

        for (auto& [v, weight] : graph[u]) {
            long long distance = curr_weight + weight + vertex_weights[v];
            if (distance < min_distance[v]) {
                min_distance[v] = distance;
                pq.push({distance, v});
            }
        }
    }

    return min_distance;
}

int main() {
    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; ++i) {
        cin >> vertex_weights[i];
    }

    for (int i = 0; i < M; ++i) {
        int u, v, b;
        cin >> u >> v >> b;
        add_edge(u, v, b);
    }

    long long min_weight_from_start = dijkstra(1);

    for (int i = 2; i <= N; ++i) {
        cout << min_weight_from_start + vertex_weights[i] << (i < N ? " " : "\n");
    }

    return 0;
}