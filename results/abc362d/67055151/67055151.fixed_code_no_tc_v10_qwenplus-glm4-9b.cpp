#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int INF = 1e9;

struct Edge {
    int to, weight;
};

vector<vector<Edge>> graph;
vector<long long> dist;

void dijkstra(int source) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> min_heap;
    min_heap.push({0, source});

    while (!min_heap.empty()) {
        long long current_dist = min_heap.top().first;
        int current_vertex = min_heap.top().second;
        min_heap.pop();

        if (dist[current_vertex] < current_dist) continue;

        for (auto& edge : graph[current_vertex]) {
            long long new_dist = current_dist + edge.weight;
            if (dist[edge.to] > new_dist) {
                dist[edge.to] = new_dist;
                min_heap.push({new_dist, edge.to});
            }
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    graph.resize(N);
    dist.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> dist[i];  // Vertex weights
    }

    for (int i = 0; i < M; i++) {
        int u, v, b;
        cin >> u >> v >> b;
        graph[u - 1].emplace_back(v - 1, b);
        graph[v - 1].emplace_back(u - 1, b);
    }

    dijkstra(0);

    for (int i = 1; i < N; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}