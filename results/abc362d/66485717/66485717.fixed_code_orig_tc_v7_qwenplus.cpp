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

struct Node {
    int x;
    long long w;
    bool operator < (const Node& u) const {
        return w == u.w ? x < u.x : w > u.w;
    }
};

constexpr long long inf = 1e18;

void solve() {
    int n, m;
    cin >> n >> m;
    V<long long> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    
    vector<vector<pair<int, long long>>> g(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    
    vector<long long> d(n + 1, inf);
    vector<bool> vis(n + 1, false);
    
    priority_queue<Node> pq;
    d[1] = a[1];
    pq.push({1, d[1]});
    
    while (!pq.empty()) {
        auto [x, w] = pq.top();
        pq.pop();
        
        if (vis[x]) continue;
        vis[x] = true;
        
        for (const auto& [y, edge_weight] : g[x]) {
            long long new_dist = d[x] + edge_weight + a[y];
            if (new_dist < d[y]) {
                d[y] = new_dist;
                pq.push({y, d[y]});
            }
        }
    }
    
    for (int i = 2; i <= n; ++i) {
        cout << d[i];
        if (i < n) cout << " ";
        else cout << "\n";
    }
}

INT main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}