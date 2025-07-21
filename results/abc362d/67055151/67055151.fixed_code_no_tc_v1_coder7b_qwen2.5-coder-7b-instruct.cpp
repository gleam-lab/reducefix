#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <unordered_set>

using namespace std;

typedef long long ll;

struct Edge {
    ll to, weight;
};

vector<ll> dijkstra(int start, int n, vector<vector<Edge>>& graph, vector<ll>& weights) {
    vector<ll> dist(n, numeric_limits<ll>::max());
    dist[start] = weights[start];
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({dist[start], start});

    while (!pq.empty()) {
        ll u = pq.top().second;
        ll d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue;

        for (const auto& edge : graph[u]) {
            ll v = edge.to;
            ll w = edge.weight;

            if (dist[u] + w + weights[v] < dist[v]) {
                dist[v] = dist[u] + w + weights[v];
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<ll> weights(n);
    for (int i = 0; i < n; ++i) {
        cin >> weights[i];
    }

    vector<vector<Edge>> graph(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v; // Convert to 0-based index
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }

    vector<ll> results(n - 1, numeric_limits<ll>::max());
    for (int i = 1; i < n; ++i) {
        results[i - 1] = dijkstra(0, n, graph, weights)[i];
    }

    for (int i = 0; i < n - 1; ++i) {
        cout << results[i] << " ";
    }
    cout << endl;

    return 0;
}