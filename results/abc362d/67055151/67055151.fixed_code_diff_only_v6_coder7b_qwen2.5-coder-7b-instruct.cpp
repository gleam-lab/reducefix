#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <utility>
#include <algorithm>

using namespace std;

typedef long long ll;

struct Edge {
    ll to, cost;
};

vector<ll> dijkstra(int n, vector<vector<Edge>>& graph, int start) {
    vector<ll> dist(n, LLONG_MAX);
    dist[start] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (auto& e : graph[u]) {
            int v = e.to, w = e.cost;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<vector<Edge>> graph(n);
    for (int i = 0; i < m; ++i) {
        int u, v, b;
        cin >> u >> v >> b;
        --u; --v;
        graph[u].emplace_back(v, b);
        graph[v].emplace_back(u, b);
    }

    vector<ll> ans(n - 1);
    for (int i = 1; i < n; ++i) {
        vector<ll> dist = dijkstra(n, graph, i);
        ans[i - 1] = dist[0] + a[0];
    }

    for (int i = 0; i < n - 1; ++i) {
        cout << ans[i] << ' ';
    }
    cout << endl;

    return 0;
}