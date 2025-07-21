#include <bits/stdc++.h>
using namespace std;
#define int long long
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
    int64_t w;
    bool operator < (const Node& other) const {
        return w > other.w;
    }
};

constexpr int64_t INF = 1LL << 60;

void solve() {
    int n, m;
    cin >> n >> m;
    V<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    VV<pair<int, int>> g(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, b;
        cin >> u >> v >> b;
        g[u].emplace_back(v, b);
        g[v].emplace_back(u, b);
    }
    V<int64_t> d(n + 1, INF);
    d[1] = a[1];
    priority_queue<Node> pq;
    pq.push({1, d[1]});
    V<bool> vis(n + 1, false);
    while (!pq.empty()) {
        auto [x, w] = pq.top();
        pq.pop();
        if (vis[x]) continue;
        vis[x] = true;
        for (auto [y, b] : g[x]) {
            if (d[y] > d[x] + b + a[y]) {
                d[y] = d[x] + b + a[y];
                pq.push({y, d[y]});
            }
        }
    }
    for (int i = 2; i <= n; ++i) {
        cout << d[i] << " \n"[i == n];
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