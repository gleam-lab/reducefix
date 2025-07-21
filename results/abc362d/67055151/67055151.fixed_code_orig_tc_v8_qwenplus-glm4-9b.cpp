#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int MAX_N = 200100;
const long long INF = (long long)1e18;

vector<pair<int, int>> graph[MAX_N]; // adjacency list
long long vertex_weights[MAX_N];
long long min_distance[MAX_N]; // minimum distance from vertex 1 to vertex i
bool visited[MAX_N]; // visited vertices

void dijkstra(int start_vertex) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, start_vertex});
    min_distance[start_vertex] = 0;

    while (!pq.empty()) {
        int vertex = pq.top().second;
        long long distance = pq.top().first;
        pq.pop();

        if (visited[vertex]) continue;
        visited[vertex] = true;

        for (auto &edge : graph[vertex]) {
            int next_vertex = edge.first;
            long long weight = edge.second;

            if (distance + weight < min_distance[next_vertex]) {
                min_distance[next_vertex] = distance + weight;
                pq.push({min_distance[next_vertex], next_vertex});
            }
        }
    }
}

int main() {
    int n, m;
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

    dijkstra(1);

    for (int i = 2; i <= n; ++i) {
        cout << min_distance[i] << " ";
    }
    cout << endl;

    return 0;
}