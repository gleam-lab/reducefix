#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int INF = INT_MAX;

struct Edge {
    int to, weight;
};

vector<Edge> adj[200005];

void dijkstra(int start, int n, vector<long long>& dist) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();

        if (d > dist[u]) continue;

        for (auto& e : adj[u]) {
            int v = e.to;
            long long w = d + e.weight + dist[u]; // Adding current node's distance to the edge weight

            if (w < dist[v]) {
                dist[v] = w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<long long> dist(n, INF);
    vector<int> val(n);

    for (int i = 0; i < n; ++i) {
        cin >> val[i];
    }

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v; // Adjusting indices to zero-based

        adj[u].push_back({v, w + val[u]});
        adj[v].push_back({u, w + val[v]});
    }

    dijkstra(0, n, dist);

    for (int i = 1; i < n; ++i) {
        cout << dist[i] + val[i] << " ";
    }
    cout << endl;

    return 0;
}