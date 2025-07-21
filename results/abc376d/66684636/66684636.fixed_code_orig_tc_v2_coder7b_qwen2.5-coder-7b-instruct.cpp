#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 5;

bool vis[N];
vector<int> g[N];
int n, m, ans = INT_MAX;

void dfs(int u, int p, int d) {
    if (d > ans) return;
    if (u == 1) {
        ans = min(ans, d);
        return;
    }
    vis[u] = true;
    for (int v : g[u]) {
        if (v == p) continue;
        dfs(v, u, d + 1);
    }
    vis[u] = false;
}

signed main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, -1, 0);
    if (ans == INT_MAX) cout << -1;
    else cout << ans;
    return 0;
}