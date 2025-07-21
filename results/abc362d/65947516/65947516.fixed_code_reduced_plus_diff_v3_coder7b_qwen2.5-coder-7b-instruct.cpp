#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

typedef long long ll;
typedef pair<ll, int> pli;

struct Edge {
    int to;
    ll weight;
};

class Graph {
private:
    int n;
    vector<Edge> adjList[];
public:
    Graph(int size) : n(size) {}

    void addEdge(int u, int v, ll w) {
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
    }

    vector<ll> dijkstra(int start) {
        vector<ll> dist(n + 1, numeric_limits<ll>::max());
        priority_queue<pli, vector<pli>, greater<pli>> pq;
        
        dist[start] = 0;
        pq.push({0, start});

        while (!pq.empty()) {
            auto [currentDist, u] = pq.top();
            pq.pop();

            if (currentDist > dist[u]) continue;

            for (auto [v, weight] : adjList[u]) {
                ll distance = currentDist + weight + dist[u];

                if (distance < dist[v]) {
                    dist[v] = distance;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    Graph g(n);

    vector<ll> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }

    vector<ll> result = g.dijkstra(1);

    for (int i = 2; i <= n; ++i) {
        cout << result[i] + a[i] << " ";
    }

    return 0;
}