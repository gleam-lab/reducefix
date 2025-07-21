#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const long long INF = numeric_limits<long long>::max();

struct Edge {
    int to;
    long long weight;
};

class Graph {
private:
    int n;
    vector<vector<Edge>> adjList;

public:
    Graph(int n) : n(n), adjList(n) {}

    void addEdge(int u, int v, long long w) {
        adjList[u].emplace_back(v, w);
        adjList[v].emplace_back(u, w);
    }

    vector<long long> dijkstra(int start) {
        vector<long long> dist(n, INF);
        dist[start] = 0;

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.emplace(0, start);

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u])
                continue;

            for (auto [v, w] : adjList[u]) {
                long long newDist = d + w;
                if (newDist < dist[v]) {
                    dist[v] = newDist;
                    pq.emplace(newDist, v);
                }
            }
        }

        return dist;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<long long> weights(n);
    for (int i = 0; i < n; ++i) {
        cin >> weights[i];
    }

    Graph g(n);

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        g.addEdge(u, v, w);
    }

    vector<long long> dists = g.dijkstra(0);

    for (int i = 1; i < n; ++i) {
        cout << dists[i] + weights[i] << " ";
    }
    cout << endl;

    return 0;
}