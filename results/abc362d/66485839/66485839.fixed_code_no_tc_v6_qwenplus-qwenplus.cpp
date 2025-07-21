#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
constexpr int N = 2e5 + 10;
constexpr i64 inf = 1e18;

struct Node {
    int x;
    i64 w;
    bool operator<(const Node& other) const {
        return w > other.w; // Min-heap based on weight
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
    for(int i = 0; i < m; ++i) {
        int u, v;
        i64 b;
        cin >> u >> v >> b;
        g[u].emplace_back(v, b);
        g[v].emplace_back(u, b);
    }

    vector<i64> d(n + 1, inf);
    vector<bool> vis(n + 1, false);
    priority_queue<Node> pq;

    // Start from node 1 with initial path weight = a[1]
    d[1] = a[1];
    pq.push({1, d[1]});

    while (!pq.empty()) {
        auto [x, _] = pq.top();
        pq.pop();

        if (vis[x]) continue;
        vis[x] = true;

        for (const auto& [y, b] : g[x]) {
            i64 new_cost = d[x] + b + a[y]; // Include vertex y's weight and edge cost
            if (new_cost < d[y]) {
                d[y] = new_cost;
                pq.push({y, d[y]});
            }
        }
    }

    for (int i = 2; i <= n; ++i) {
        cout << d[i] << " ";
    }
    cout << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}