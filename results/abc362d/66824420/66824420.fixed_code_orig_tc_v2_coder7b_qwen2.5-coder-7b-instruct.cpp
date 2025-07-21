#include <bits/stdc++.h>
using namespace std;

#define INF 1e10 + 7

struct Edge {
    int u, v, w;
};

class Graph {
private:
    vector<vector<Edge>> adjList;
    vector<long long> dist;

public:
    Graph(int n) {
        adjList.resize(n + 1);
        dist.resize(n + 1, INF);
    }

    void addEdge(int u, int v, int w) {
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
    }

    void dijkstra(int src) {
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();

            if (d > dist[u]) continue;

            for (auto& [v, w] : adjList[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
    }

    long long getMinPathWeight(int node) {
        return dist[node];
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, m;
    cin >> n >> m;
    
    Graph g(n);

    vector<int> a(n);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }

    g.dijkstra(1);

    for (int i = 2; i <= n; ++i) {
        cout << g.getMinPathWeight(i) + a[i] << " ";
    }

    return 0;
}