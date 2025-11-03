#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
constexpr int N = 2e5 + 10;
constexpr i64 inf = 1e18;

struct Node {
    int x;
    i64 w;
    bool operator < (const Node& u) const {
        return w > u.w;
    }
};

vector<pair<int, int>> g[N];
i64 d[N];
bool vis[N];

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<i64> a(n + 1);
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
    fill(d, d + n + 1, inf);
    fill(vis, vis + n + 1, false);
    
    d[1] = a[1];
    pq.push({1, d[1]});
    
    while (!pq.empty()) {
        auto [x, w] = pq.top();
        pq.pop();
        
        if (vis[x]) continue;
        vis[x] = true;
        
        for (const auto& [y, dw] : g[x]) {
            i64 new_cost = d[x] + dw + a[y];
            if (new_cost < d[y]) {
                d[y] = new_cost;
                pq.push({y, d[y]});
            }
        }
    }
    
    for (int i = 2; i <= n; ++i) {
        cout << d[i];
        if (i < n) cout << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}