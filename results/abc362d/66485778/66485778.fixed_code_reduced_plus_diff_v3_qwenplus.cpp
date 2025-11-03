#include <bits/stdc++.h>
using namespace std;

#define int long long
using i64 = long long;
using V = vector<int>;
using VV = vector<vector<int>>;

struct Node {
    int x, w;
    bool operator < (const Node& u) const {
        return w > u.w;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    V a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    
    vector<vector<pair<int, int>>> g(n + 1);
    for (int i = 0; i < m; ++i) {
        int x, y, c;
        cin >> x >> y >> c;
        g[x].emplace_back(y, c);
        g[y].emplace_back(x, c);
    }
    
    V d(n + 1, LLONG_MAX);
    vector<bool> vis(n + 1, false);
    
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

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}