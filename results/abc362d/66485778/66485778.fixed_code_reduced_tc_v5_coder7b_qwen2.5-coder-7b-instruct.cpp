#include <bits/stdc++.h>
using namespace std;

#define LL long long

struct Node {
    int v, dist;
    bool operator<(const Node &other) const {
        return dist > other.dist;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<LL> a(n + 1), dist(n + 1, LLONG_MAX);
    vector<vector<pair<int, LL>>> adj(n + 1);

    for (int i = 1; i <= n; ++i) cin >> a[i];

    for (int i = 0; i < m; ++i) {
        int u, v, b;
        cin >> u >> v >> b;
        adj[u].push_back({v, b});
        adj[v].push_back({u, b});
    }

    priority_queue<Node> pq;
    dist[1] = a[1];
    pq.push({1, dist[1]});

    while (!pq.empty()) {
        auto [u, d] = pq.top(); pq.pop();

        if (d > dist[u]) continue;

        for (auto &[v, b] : adj[u]) {
            if (dist[u] + b + a[v] < dist[v]) {
                dist[v] = dist[u] + b + a[v];
                pq.push({v, dist[v]});
            }
        }
    }

    for (int i = 2; i <= n; ++i) cout << min(dist[i], LLONG_MAX) << ' ';
    cout << '\n';

    return 0;
}