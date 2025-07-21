#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 5;
const int INF = 1e18;

vector<int> g[N];
int dist[N];
int parent[N];
int n, m, ans = INF;

void bfs() {
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v : g[u]) {
            if (v == 1 && dist[u] + 1 < ans) {
                ans = dist[u] + 1;
                continue;
            }
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);
            } else if (parent[u] != v) {
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
        g[v].push_back(u); // Assuming undirected graph for cycle detection
    }
    
    memset(dist, -1, sizeof(dist));
    memset(parent, -1, sizeof(parent));
    bfs();
    
    if (ans != INF) cout << ans;
    else cout << -1;
    return 0;
}