#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = pair<int, int>;

struct Node {
    int u;
    i64 dist;
    bool operator<(const Node& other) const {
        return dist > other.dist;
    }
};

void solve2() {
    int n, m;
    cin >> n >> m;
    vector<i64> A(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
    }

    vector<vector<pii>> graph(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        i64 b;
        cin >> u >> v >> b;
        graph[u].emplace_back(v, b);
        graph[v].emplace_back(u, b);
    }

    const i64 INF = numeric_limits<i64>::max() / 2;
    vector<i64> d(n + 1, INF);
    priority_queue<Node> pq;

    d[1] = A[1];
    pq.push({1, d[1]});

    while (!pq.empty()) {
        auto [u, dist_u] = pq.top();
        pq.pop();

        if (dist_u > d[u]) continue;

        for (auto [v, cost] : graph[u]) {
            i64 new_dist = d[u] + cost + A[v];
            if (new_dist < d[v]) {
                d[v] = new_dist;
                pq.push({v, d[v]});
            }
        }
    }

    for (int i = 2; i <= n; ++i) {
        cout << d[i];
        if (i != n) cout << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve2();
    }
    return 0;
}