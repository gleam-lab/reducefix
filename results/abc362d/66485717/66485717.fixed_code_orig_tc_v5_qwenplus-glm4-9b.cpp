#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int MAXN = 200010;
int n, m;
vector<pair<int, int>> adj[MAXN]; // adj[i] stores the edges from vertex i
int vertex_weights[MAXN]; // vertex_weights[i] stores the weight of vertex i

struct Edge {
    int to, weight;
    Edge(int to, int weight) : to(to), weight(weight) {}
};

struct Compare {
    bool operator()(Edge a, Edge b) {
        return a.weight > b.weight;
    }
};

void dijkstra(int src) {
    priority_queue<Edge, vector<Edge>, Compare> pq;
    vector<int> dist(MAXN, INT_MAX);
    dist[src] = 0;

    pq.push(Edge(src, 0));

    while (!pq.empty()) {
        int u = pq.top().to;
        int d = pq.top().weight;
        pq.pop();

        if (d != dist[u]) continue;

        for (auto& e : adj[u]) {
            int v = e.first;
            int edge_weight = e.second;
            int new_dist = d + vertex_weights[u] + edge_weight;

            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.push(Edge(v, new_dist));
            }
        }
    }

    for (int i = 2; i <= n; ++i) {
        cout << dist[i] << (i == n ? "\n" : " ");
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> vertex_weights[i];
    }

    int u, v, w;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    dijkstra(1);

    return 0;
}