#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 5;

bool vis[N];
vector <int> g[N];
int n, m, ans;

void bfs(int start) {
    queue<int> q;
    q.push(start);
    vis[start] = true;
    int depth = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : g[u]) {
            if (!vis[v]) {
                vis[v] = true;
                q.push(v);
                depth++;
            }
        }
    }
    ans = min(ans, depth);
}

signed main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u); // Assuming undirected graph
    }
    vis[1] = true; // Start BFS from vertex 1
    bfs(1);
    if (ans == 0) cout << -1;
    else cout << ans;
    return 0;
}