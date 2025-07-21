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
struct DSU {
    // ... DSU structure remains the same ...
};
struct Edge {
    // ... Edge structure remains the same ...
};
using i64 = long long;
void solve() {
    // ... The content of the solve function remains the same ...
}
struct Node {
    int x, w;
    bool operator<(const Node& u) const {
        return w < u.w; // Priority queue should prioritize smaller weights
    }
};
constexpr int N = 3e5 + 10;
constexpr i64 INF = 1e10;
priority_queue<Node> pq;
vector<pair<int, int>> g[N];
void solve2() {
    int n, m;
    cin >> n >> m;
    V<int> a(n + 1, 0);
    V<i64> d(n + 1, INF);
    d[1] = 0; // Starting point
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; ++i) {
        int x, y, c;
        cin >> x >> y >> c;
        g[x].emplace_back(y, c);
        g[y].emplace_back(x, c);
    }
    pq.emplace(1, 0);
    while (!pq.empty()) {
        auto [x, w] = pq.top();
        pq.pop();
        if (x == 1 || w > d[x]) continue;
        for (const auto& [y, dw] : g[x]) {
            if (w + dw < d[y]) {
                d[y] = w + dw;
                pq.emplace(y, d[y]);
            }
        }
    }
    for (int i = 2; i <= n; ++i) {
        cout << d[i] << (i == n ? "" : " ");
    }
}
INT main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve2();
        continue;
        solve();
    }
    return 0;
}