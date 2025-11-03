#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
constexpr int N = 200010;
constexpr i64 inf = 1e18;

struct Node {
    int x;
    i64 w;
    bool operator < (const Node& u) const {
        return w > u.w; // Min-heap: smaller weight has higher priority
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
    
    // Initialize distances
    for (int i = 1; i <= n; ++i) {
        d[i] = inf;
        vis[i] = false;
    }
    
    priority_queue<Node> pq;
    d[1] = a[1]; // Starting at vertex 1, we pay its vertex weight
    pq.push({1, d[1]});
    
    while (!pq.empty()) {
        auto [x, w] = pq.top();
        pq.pop();
        
        if (vis[x]) continue;
        vis[x] = true;
        
        for (const auto& [y, edge_weight] : g[x]) {
            i64 new_dist = d[x] + edge_weight + a[y];
            if (new_dist < d[y]) {
                d[y] = new_dist;
                pq.push({y, d[y]});
            }
        }
    }
    
    // Output results for vertices 2 to N
    for (int i = 2; i <= n; ++i) {
        cout << d[i];
        if (i < n) cout << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    return 0;
}