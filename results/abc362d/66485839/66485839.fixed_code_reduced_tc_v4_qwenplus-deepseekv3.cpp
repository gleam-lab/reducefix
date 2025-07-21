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
    bool operator < (const Node& u) const {
        return w > u.w;
    }
};

constexpr int64_t inf = 1LL << 60;

void solve() {
    int n, m;
    cin >> n >> m;
    V<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    VV<pair<int, int>> g(n + 1);
    for (int i = 0; i < m; ++i) {
        int x, y, c;
        cin >> x >> y >> c;
        g[x].emplace_back(y, c);
        g[y].emplace_back(x, c);
    }
    V<int64_t> d(n + 1, inf);
    V<bool> vis(n + 1, false);
    priority_queue<Node> pq;
    d[1] = a[1];
    pq.push({1, d[1]});
    while (!pq.empty()) {
        auto [x, w] = pq.top();
        pq.pop();
        if (vis[x]) continue;
        vis[x] = true;
        for (const auto& [y, dw] : g[x]) {
            if (d[x] + dw + a[y] < d[y]) {
                d[y] = d[x] + dw + a[y];
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