#include <bits/stdc++.h>
using namespace std;

constexpr int N = 2e5 + 10;
constexpr long long inf = 1e18;

struct Node {
    int x;
    long long w;
    bool operator < (const Node& u) const {
        return w == u.w ? x < u.x : w > u.w;
    }
};

vector<pair<int, int>> g[N];

void solve() {
    int n, m;
    cin >> n >> m;
    vector<long long> a(n + 1, 0);
    vector<long long> d(n + 1, inf);
    vector<bool> vis(n + 1, false);

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 1; i <= m; ++i) {
        int x, y, c;
        cin >> x >> y >> c;
        g[x].emplace_back(y, c);
        g[y].emplace_back(x, c);
    }

    priority_queue<Node> pq;
    pq.emplace(1, d[1] = a[1]);

    while (!pq.empty()) {
        auto [x, w] = pq.top();
        pq.pop();

        if (vis[x]) continue;
        vis[x] = true;

        for (const auto& [y, dw] : g[x]) {
            if (d[x] + dw + a[y] < d[y]) {
                d[y] = d[x] + dw + a[y];
                pq.emplace(y, d[y]);
            }
        }
    }

    for (int i = 2; i <= n; ++i) {
        cout << min(d[i], (long long)a[i]) << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}