#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 5;

vector<int> g[N];
int n, m, ans = 1e18;

// BFS is more suitable for shortest cycle detection
void bfs(int u) {
    vector<int> dist(n + 1, -1);
    queue<int> q;
    
    dist[u] = 0;
    q.push(u);
    
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        
        for (int nei : g[v]) {
            if (dist[nei] == -1) {
                dist[nei] = dist[v] + 1;
                q.push(nei);
            } else if (nei == u && dist[v] >= 2) {
                // Found a cycle back to the starting node
                ans = min(ans, dist[v] + 1);
            }
        }
    }
}

signed main() {
    cin >> n >> m;
    
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    
    // To find shortest cycle containing node 1
    bfs(1);
    
    if (ans != 1e18) cout << ans;
    else cout << -1;
    
    return 0;
}