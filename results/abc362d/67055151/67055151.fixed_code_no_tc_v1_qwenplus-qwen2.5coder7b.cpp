#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <climits>

using namespace std;

typedef long long ll;

struct Edge {
    ll to, cost;
    Edge(ll t, ll c) : to(t), cost(c) {}
};

void dijkstra(int start, vector<vector<Edge>>& graph, vector<ll>& dist) {
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    dist[start] = 0;
    pq.push({dist[start], start});

    while (!pq.empty()) {
        ll u = pq.top().second;
        ll d = pq.top().first;
        pq.pop();

        if (d > dist[u])
            continue;

        for (Edge& e : graph[u]) {
            ll v = e.to;
            ll cost = e.cost;

            if (dist[v] > dist[u] + cost) {
                dist[v] = dist[u] + cost;
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

    vector<ll> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    vector<vector<Edge>> graph(n);
    for (int i = 0; i < m; ++i) {
        int u, v, b;
        cin >> u >> v >> b;
        --u, --v; // Convert to 0-based index
        graph[u].emplace_back(v, b);
        graph[v].emplace_back(u, b);
    }

    vector<ll> dist(n, LLONG_MAX);
    dist[0] = a[0];
    dijkstra(0, graph, dist);

    for (int i = 1; i < n; ++i)
        cout << dist[i] << " ";

    return 0;
}