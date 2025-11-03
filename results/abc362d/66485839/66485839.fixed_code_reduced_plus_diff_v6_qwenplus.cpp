#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pbk push_back
template <class T>
using V = vector<T>;
template <class T>
using VV = vector<vector<T>>;
template <class T>
using VVV = vector<vector<vector<T>>>;

struct Node {
    int x, w;
    bool operator < (const Node& u) const {
        return w > u.w;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    V<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    
    vector<vector<pair<int, int>>> g(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].pbk({v, w});
        g[v].pbk({u, w});
    }
    
    V<int> dist(n + 1, LLONG_MAX);
    vector<bool> visited(n + 1, false);
    
    priority_queue<Node> pq;
    dist[1] = a[1];
    pq.push({1, a[1]});
    
    while (!pq.empty()) {
        auto [u, d] = pq.top();
        pq.pop();
        
        if (visited[u]) continue;
        visited[u] = true;
        
        for (auto [v, edge_weight] : g[u]) {
            int new_dist = dist[u] + edge_weight + a[v];
            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.push({v, new_dist});
            }
        }
    }
    
    for (int i = 2; i <= n; ++i) {
        cout << dist[i];
        if (i < n) cout << " ";
        else cout << "\n";
    }
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}