#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()

typedef long long ll;

struct Edge {
    ll to, cost;
};

vector<Edge> graph[200005];
vector<ll> dist(200005, LLONG_MAX);

void dijkstra(int start) {
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (auto &[v, w] : graph[u]) {
            ll nd = d + w + dist[v];
            if (nd < dist[v]) {
                dist[v] = nd;
                pq.push({nd, v});
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
    for (int i = 0; i < n; ++i) cin >> a[i];

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }

    dijkstra(0);

    for (int i = 1; i < n; ++i) {
        cout << dist[i] + a[i] << ' ';
    }

    return 0;
}