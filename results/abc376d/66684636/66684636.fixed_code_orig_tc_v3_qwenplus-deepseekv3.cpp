#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 5;
const int INF = 1e18;

vector<int> g[N];
int n, m, ans = INF;

void bfs(int src) {
    vector<int> dist(n + 1, -1);
    vector<int> parent(n + 1, -1);
    queue<int> q;
    q.push(src);
    dist[src] = 0;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v : g[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);
            } else if (parent[u] != v && parent[v] != u) {
                ans = min(ans, dist[u] + dist[v] + 1);
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
        g[v].push_back(u);
    }
    
    for (int i = 1; i <= n && ans > 3; i++) {
        bfs(i);
    }
    
    if (ans != INF) cout << ans;
    else cout << -1;
    
    return 0;
}