#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

const int INF = 1e9;

struct Edge {
    int to, weight;
};

vector<Edge> adj[200005];
vector<long long> dist(200005, INF);

void dijkstra(int start) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({start, 0});
    dist[start] = 0;

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u])
            continue;

        for (auto &[v, w] : adj[u]) {
            long long new_dist = d + w + dist[u];
            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> val(n);
    for (int i = 0; i < n; ++i)
        cin >> val[i];

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    dijkstra(0);

    for (int i = 1; i < n; ++i)
        cout << dist[i] + val[i] << " ";

    return 0;
}