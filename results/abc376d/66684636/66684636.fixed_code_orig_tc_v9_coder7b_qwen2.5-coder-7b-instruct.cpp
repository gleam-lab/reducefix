#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 5;

bool vis[N];
vector<int> g[N];
int n, m, ans = INT_MAX;

void bfs() {
    queue<pair<int, int>> q;
    q.push({1, 0});
    vis[1] = true;

    while (!q.empty()) {
        auto [u, cnt] = q.front();
        q.pop();

        if (u == n) {
            ans = min(ans, cnt);
            continue;
        }

        for (int v : g[u]) {
            if (!vis[v]) {
                vis[v] = true;
                q.push({v, cnt + 1});
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
        g[v].push_back(u); // Since the graph is undirected
    }
    
    memset(vis, false, sizeof(vis));
    bfs();
    
    if (ans != INT_MAX) cout << ans << endl;
    else cout << -1 << endl;
    
    return 0;
}