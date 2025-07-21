#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int INF = 1e9;

struct Edge {
    int to;
    int weight;
};

vector<Edge> adj[200001]; // Assuming max vertex number is 200,000
int dist[200001]; // Distance from 1 to each vertex

void dijkstra() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Start from vertex 1
    pq.push({0, 1});
    dist[1] = 0;

    while (!pq.empty()) {
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (dist[node] < d) continue;

        for (auto& edge : adj[node]) {
            int nextNode = edge.to;
            int weight = edge.weight;
            int newDist = d + weight;

            if (newDist < dist[nextNode]) {
                dist[nextNode] = newDist;
                pq.push({newDist, nextNode});
            }
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> dist[i]; // Input vertex weights
    }

    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    dijkstra();

    for (int i = 2; i <= N; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}