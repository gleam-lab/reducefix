#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int to;
    int weight;
};

using Graph = vector<vector<Edge>>;

void dijkstra(const Graph& graph, int start, vector<int>& dist) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty()) {
        int current_dist = pq.top().first;
        int current_vertex = pq.top().second;
        pq.pop();

        if (current_dist > dist[current_vertex]) {
            continue;
        }

        for (const Edge& edge : graph[current_vertex]) {
            int next_vertex = edge.to;
            int next_dist = current_dist + edge.weight;

            if (next_dist < dist[next_vertex]) {
                dist[next_vertex] = next_dist;
                pq.push({next_dist, next_vertex});
            }
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    Graph graph(N);

    for (int i = 0; i < M; ++i) {
        int u, v, b;
        cin >> u >> v >> b;
        --u; --v;
        graph[u].push_back({v, b});
        graph[v].push_back({u, b});
    }

    vector<int> dist(N, INF);
    dijkstra(graph, 0, dist);

    for (int i = 1; i < N; ++i) {
        cout << dist[i] + A[i] << " ";
    }
    cout << endl;

    return 0;
}