#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

struct Edge {
    int to, cost;
};

class Graph {
private:
    int n;
    vector<vector<Edge>> adj;
public:
    Graph(int n): n(n), adj(n) {}

    void addEdge(int from, int to, int cost) {
        adj[from].emplace_back(to, cost);
        adj[to].emplace_back(from, cost);
    }

    vector<long long> dijkstra(int start) {
        vector<long long> dist(n, 1LL << 60);
        dist[start] = 0;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        pq.emplace(dist[start], start);

        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();

            if (d > dist[u]) continue;

            for (auto [v, w]: adj[u]) {
                long long nd = d + w;
                if (nd < dist[v]) {
                    dist[v] = nd;
                    pq.emplace(nd, v);
                }
            }
        }
        return dist;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    Graph g(n);

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        g.addEdge(u, v, w);
    }

    vector<long long> dist = g.dijkstra(0);

    for (int i = 1; i < n; ++i) {
        cout << dist[i] + a[i] << " ";
    }

    return 0;
}