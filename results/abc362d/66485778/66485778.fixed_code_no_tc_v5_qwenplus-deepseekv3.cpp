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

constexpr int N = 2e5 + 10;
constexpr int64_t inf = 1e18;

struct Node {
    int x;
    int64_t w;
    bool operator < (const Node& u) const {
        return w > u.w;
    }
};

vector<pair<int, int>> g[N];

void solve() {
    int n, m;
    cin >> n >> m;
    V<int> a(n + 1);
    vector<int64_t> d(n + 1, inf);
    vector<bool> vis(n + 1, false);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; ++i) {
        int x, y, c;
        cin >> x >> y >> c;
        g[x].emplace_back(y, c + a[y]);
        g[y].emplace_back(x, c + a[x]);
    }
    priority_queue<Node> pq;
    pq.push({1, a[1]});
    d[1] = a[1];
    while (!pq.empty()) {
        auto [x, w] = pq.top();
        pq.pop();
        if (vis[x]) continue;
        vis[x] = true;
        for (const auto& [y, dw] : g[x]) {
            if (d[x] + dw < d[y]) {
                d[y] = d[x] + dw;
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