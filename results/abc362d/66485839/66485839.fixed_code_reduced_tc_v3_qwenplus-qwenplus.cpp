#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
constexpr long long INF = 9223372036854775807;

struct Node {
    int x;
    i64 w;
    bool operator<(const Node& other) const {
        return w > other.w;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<i64> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    vector<vector<pair<int, i64>>> g(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        i64 b;
        cin >> u >> v >> b;
        g[u].emplace_back(v, b);
        g[v].emplace_back(u, b);
    }

    vector<i64> dist(n + 1, INF);
    priority_queue<Node> pq;
    dist[1] = a[1];  // Start at vertex 1, include its value
    pq.push({1, dist[1]});

    while (!pq.empty()) {
        auto [u, cost] = pq.top();
        pq.pop();

        if (cost > dist[u]) continue;

        for (auto [v, edge_cost] : g[u]) {
            i64 new_cost = cost + edge_cost + a[v];
            if (new_cost < dist[v]) {
                dist[v] = new_cost;
                pq.push({v, new_cost});
            }
        }
    }

    for (int i = 2; i <= n; ++i) {
        cout << dist[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}