#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int MAX_N = 200010;
vector<pair<int, int>> graph[MAX_N]; // adjacency list
int vertex_weights[MAX_N]; // vertex weights
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // min-heap for Dijkstra's algorithm

void dijkstra(int start) {
    int dist[MAX_N];
    fill(dist, dist + MAX_N, numeric_limits<int>::max());
    dist[start] = vertex_weights[start]; // start distance includes vertex weight

    pq.push(make_pair(dist[start], start));

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto &edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;
            int alt = dist[u] + weight + vertex_weights[v]; // new path distance
            if (dist[v] > alt) {
                dist[v] = alt;
                pq.push(make_pair(alt, v));
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    // Read vertex weights
    for (int i = 1; i <= n; ++i) {
        cin >> vertex_weights[i];
    }

    // Read edges
    for (int i = 0; i < m; ++i) {
        int x, y, w;
        cin >> x >> y >> w;
        graph[x].push_back(make_pair(y, w));
        graph[y].push_back(make_pair(x, w));
    }

    dijkstra(1); // Perform Dijkstra's algorithm starting from vertex 1

    // Output the minimum weights for paths from vertex 1 to all other vertices
    for (int i = 2; i <= n; ++i) {
        cout << dist[i] << (i < n ? " " : "\n");
    }

    return 0;
}