#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int INF = 0x3f3f3f3f;

struct Edge {
    int to, cost;
    Edge(int to, int cost) : to(to), cost(cost) {}
};

class Dijkstra {
public:
    vector<int> dijkstra(vector<vector<Edge>>& graph, int start) {
        int n = graph.size();
        vector<int> dist(n, INF);
        dist[start] = 0;
        priority_queue<PII, vector<PII>, greater<PII>> pq;
        pq.push({start, 0});

        while (!pq.empty()) {
            auto [u, d] = pq.top(); pq.pop();
            if (d > dist[u]) continue;
            for (auto& e : graph[u]) {
                int v = e.to, w = e.cost;
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.push({v, dist[v]});
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
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<vector<Edge>> graph(n);
    for (int i = 0; i < m; ++i) {
        int u, v, b;
        cin >> u >> v >> b;
        --u, --v;
        graph[u].emplace_back(v, b);
        graph[v].emplace_back(u, b);
    }

    Dijkstra dijkstra;
    vector<int> dist = dijkstra.dijkstra(graph, 0);

    for (int i = 1; i < n; ++i) {
        if (dist[i] == INF) cout << -1 << " ";
        else cout << dist[i] + a[i] << " ";
    }

    return 0;
}