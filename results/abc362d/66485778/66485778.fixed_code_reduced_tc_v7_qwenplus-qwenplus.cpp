#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
struct Node {
    int x;
    i64 w;
    bool operator < (const Node& other) const {
        return w > other.w;
    }
};

constexpr int N = 2 * 1e5 + 10;
const i64 inf = 1e18;

priority_queue<Node> pq;
vector<pair<int, i64>> g[N];

void solve() {
    int n, m;
    cin >> n >> m;
    vector<i64> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < m; ++i) {
        int u, v;
        i64 b;
        cin >> u >> v >> b;
        g[u].emplace_back(v, b);
        g[v].emplace_back(u, b);
    }

    vector<i64> d(n + 1, inf);
    vector<bool> vis(n + 1, false);
    d[1] = a[1];
    pq.push({1, d[1]});

    while (!pq.empty()) {
        auto [x, w] = pq.top();
        pq.pop();
        if (vis[x]) continue;
        vis[x] = true;

        for (auto &[y, cost] : g[x]) {
            if (d[y] > d[x] + cost + a[y]) {
                d[y] = d[x] + cost + a[y];
                pq.push({y, d[y]});
            }
        }
    }

    for (int i = 2; i <= n; ++i) {
        cout << d[i] << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}