#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct Node {
    int x;
    i64 w;
    bool operator < (const Node& u) const {
        return w > u.w; // Correct comparator for min-heap
    }
};

constexpr i64 inf = 1e18;
priority_queue<Node> pq;
vector<pair<int, i64>> g[200005]; // Adjusted size to fit constraints
i64 d[200005];
bool vis[200005];

void solve() {
    int n, m;
    cin >> n >> m;
    vector<i64> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        g[i].clear();
        d[i] = inf;
        vis[i] = false;
    }
    for (int i = 1; i <= m; ++i) {
        int x, y;
        i64 c;
        cin >> x >> y >> c;
        g[x].emplace_back(y, c);
        g[y].emplace_back(x, c);
    }
    pq.emplace(Node{1, a[1]});
    d[1] = a[1];
    while (!pq.empty()) {
        auto [x, w] = pq.top();
        pq.pop();
        if (vis[x]) continue;
        vis[x] = true;
        for (const auto& [y, dw] : g[x]) {
            if (d[x] + dw + a[y] < d[y]) {
                d[y] = d[x] + dw + a[y];
                pq.emplace(Node{y, d[y]});
            }
        }
    }
    for (int i = 2; i <= n; ++i) {
        cout << d[i] << " \n"[i == n];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}