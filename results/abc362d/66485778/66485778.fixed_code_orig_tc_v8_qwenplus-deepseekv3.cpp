#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

constexpr i64 INF = 1e18;

struct Edge {
    int to;
    i64 cost;
};

struct Node {
    int v;
    i64 cost;
    bool operator<(const Node& other) const {
        return cost > other.cost;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<i64> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    vector<vector<Edge>> g(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        i64 b;
        cin >> u >> v >> b;
        g[u].push_back({v, b + a[v]});
        g[v].push_back({u, b + a[u]});
    }

    vector<i64> dist(n + 1, INF);
    priority_queue<Node> pq;
    dist[1] = a[1];
    pq.push({1, dist[1]});

    while (!pq.empty()) {
        Node node = pq.top();
        pq.pop();
        int u = node.v;
        if (node.cost > dist[u]) continue;

        for (const Edge& e : g[u]) {
            int v = e.to;
            i64 new_cost = dist[u] + e.cost;
            if (new_cost < dist[v]) {
                dist[v] = new_cost;
                pq.push({v, dist[v]});
            }
        }
    }

    for (int i = 2; i <= n; ++i) {
        cout << dist[i] << " \n"[i == n];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}