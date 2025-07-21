#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int INF = INT_MAX;

struct Edge {
    int to, weight;
};

class Graph {
public:
    int V;
    vector<vector<Edge>> adj;

    Graph(int V) : V(V), adj(V) {}

    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // Assuming an undirected graph
    }

    void dijkstra(int src, vector<long long>& dist) {
        dist.assign(V, INF);
        dist[src] = 0;

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();

            if (d > dist[u]) continue;

            for (auto [v, w] : adj[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
    }
};

int main() {
    int N, M;
    cin >> N >> M;

    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    Graph g(N);
    for (int i = 0; i < M; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v; // Convert to zero-based indexing
        g.addEdge(u, v, w + A[u] + A[v]);
    }

    vector<long long> dist(N);
    g.dijkstra(0, dist);

    for (int i = 1; i < N; ++i) {
        cout << dist[i] + A[i] << " ";
    }
    cout << endl;

    return 0;
}