#include <bits/stdc++.h>
using namespace std;

#define MAX_N 200010
#define INF (int)1e9

int n, m;
int vertex_weights[MAX_N];
int adjacency_list[MAX_N][MAX_N];  // Use this instead of vector<pair<int, int>> g[N];
int dist[MAX_N];

void dijkstra(int source) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, source});  // Push the source with 0 distance
    dist[source] = vertex_weights[source];  // Set the distance to the source vertex itself

    while (!pq.empty()) {
        int current_dist = pq.top().first;
        int current_vertex = pq.top().second;
        pq.pop();

        if (current_dist != dist[current_vertex]) continue;

        for (int i = 0; i < n; ++i) {
            if (adjacency_list[current_vertex][i] != -1) {  // Check if the edge exists
                int next_vertex = i;
                int edge_weight = adjacency_list[current_vertex][i];
                int new_dist = current_dist + vertex_weights[next_vertex] + edge_weight;

                if (new_dist < dist[next_vertex]) {
                    dist[next_vertex] = new_dist;
                    pq.push({new_dist, next_vertex});
                }
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &vertex_weights[i]);
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            adjacency_list[i][j] = -1;  // Initialize with -1 to indicate no edge
        }
    }

    for (int i = 0; i < m; ++i) {
        int u, v, b;
        scanf("%d %d %d", &u, &v, &b);
        adjacency_list[u][v] = b;
        adjacency_list[v][u] = b;  // Since the graph is undirected
    }

    dijkstra(1);

    for (int i = 2; i <= n; ++i) {
        printf("%d ", dist[i]);
    }

    return 0;
}