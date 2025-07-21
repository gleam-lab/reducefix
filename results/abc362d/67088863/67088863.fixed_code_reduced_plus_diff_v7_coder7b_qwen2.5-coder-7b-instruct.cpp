#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 200005;
const long long INF = 1e18;

struct Edge {
    int to;
    long long weight;
};

vector<Edge> adj[MAXN];

long long dijkstra(int start, int n) {
    vector<long long> dist(n, INF);
    dist[start] = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist[n - 1];
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    for (int i = 0; i < m; ++i) {
        int u, v, b;
        cin >> u >> v >> b;
        --u, --v; // Convert to zero-based index
        adj[u].push_back({v, b + a[u]});
        adj[v].push_back({u, b + a[v]});
    }

    for (int i = 1; i < n; ++i) {
        cout << dijkstra(i, n) + a[i] << " ";
    }
    cout << endl;

    return 0;
}