#include <bits/stdc++.h>
using namespace std;
#define INT signed
#define pbk push_back
template <class T>
using V = vector<T>;
template <class T>
using VV = vector<vector<T>>;
template <class T>
using VVV = vector<vector<vector<T>>>;

struct Node {
    int x;
    long long w;
    bool operator < (const Node& u) const {
        return w > u.w; // Min-heap: smaller weight has higher priority
    }
};

using i64 = long long;
constexpr i64 INF = 1e18;

void solve() {
    int n, m;
    cin >> n >> m;
    V<i64> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    vector<vector<pair<int, i64>>> g(n + 1);
    for (int i = 0; i < m; ++i) {
        int x, y;
        i64 c;
        cin >> x >> y >> c;
        g[x].emplace_back(y, c);
        g[y].emplace_back(x, c);
    }

    vector<i64> dist(n + 1, INF);
    vector<bool> visited(n + 1, false);
    priority_queue<Node> pq;

    // Start from vertex 1 with initial cost = a[1]
    dist[1] = a[1];
    pq.push({1, dist[1]});

    while (!pq.empty()) {
        auto [u, d] = pq.top();
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (const auto& [v, edge_weight] : g[u]) {
            i64 new_cost = dist[u] + edge_weight + a[v];
            if (new_cost < dist[v]) {
                dist[v] = new_cost;
                pq.push({v, new_cost});
            }
        }
    }

    // Output results for vertices 2 to N
    for (int i = 2; i <= n; ++i) {
        cout << dist[i];
        if (i < n) cout << ' ';
        else cout << '\n';
    }
}

INT main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}