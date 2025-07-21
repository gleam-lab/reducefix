#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int INF = INT_MAX;

struct Edge {
    int to, weight;
};

vector<Edge> graph[200001]; // Adjust size according to constraints
vector<int> vertex_weights(200001);
int n, m;

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n+1, INF);

    pq.push({0, start});
    dist[start] = vertex_weights[start];

    while (!pq.empty()) {
        int current_dist = pq.top().first;
        int current_vertex = pq.top().second;
        pq.pop();

        if (current_dist > dist[current_vertex]) continue;

        for (auto& edge : graph[current_vertex]) {
            int next_vertex = edge.to;
            int next_dist = current_dist + edge.weight + vertex_weights[next_vertex];

            if (next_dist < dist[next_vertex]) {
                dist[next_vertex] = next_dist;
                pq.push({next_dist, next_vertex});
            }
        }
    }

    // Output the results for each vertex
    for (int i = 2; i <= n; ++i) {
        cout << dist[i] << (i == n ? "\n" : " ");
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> vertex_weights[i];
    }
    for (int i = 0; i < m; ++i) {
        int u, v, b;
        cin >> u >> v >> b;
        graph[u].push_back({v, b});
        graph[v].push_back({u, b});
    }
    dijkstra(1); // Start Dijkstra's algorithm from vertex 1
    return 0;
}