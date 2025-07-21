#include<bits/stdc++.h>
using namespace std;

typedef pair<long long, long long> PII;
const long long INF = 1e18;

struct Edge {
    long long to, cost;
};

class Graph {
public:
    vector<vector<Edge>> adj;
    vector<long long> dist;

    Graph(long long n) : adj(n), dist(n, INF) {}

    void addEdge(long long u, long long v, long long w) {
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    void dijkstra(long long s) {
        priority_queue<PII, vector<PII>, greater<PII>> pq;
        pq.emplace(0, s);
        dist[s] = 0;

        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d > dist[u]) continue;

            for (auto& [v, w] : adj[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.emplace(dist[v], v);
                }
            }
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    long long n, m;
    cin >> n >> m;

    Graph g(n+1);
    vector<long long> a(n+1);
    for (long long i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (long long i = 1; i <= m; ++i) {
        long long u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }

    g.dijkstra(1);

    for (long long i = 2; i <= n; ++i) {
        cout << g.dist[i] + a[i] << " ";
    }

    return 0;
}