#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<long long, int> pii;

const long long INF = LLONG_MAX;

struct Graph {
    int n, m;
    vector<vector<pii>> adj;
    vector<int> weights;

    Graph(int _n, int _m) : n(_n), m(_m), adj(n), weights(n) {}

    void addEdge(int u, int v, int w) {
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    void dijkstra(int start) {
        vector<long long> dist(n, INF);
        dist[start] = 0;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.emplace(0, start);

        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();

            if (d > dist[u]) continue;

            for (auto [v, w] : adj[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.emplace(dist[v], v);
                }
            }
        }

        for (int i = 1; i < n; ++i) {
            cout << dist[i] + weights[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    Graph g(n, m);

    for (int i = 0; i < n; ++i) {
        cin >> g.weights[i];
    }

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v; // Adjusting for zero-based indexing
        g.addEdge(u, v, w);
    }

    g.dijkstra(0); // Start from vertex 0 (index 0)

    return 0;
}