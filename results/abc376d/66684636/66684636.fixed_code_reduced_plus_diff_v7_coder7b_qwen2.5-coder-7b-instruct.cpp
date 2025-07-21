#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 5;

bool vis[N];
vector<pair<int, int>> g[N];
int n, m, ans = INT_MAX;

void dfs(int u, int cnt)
{
    if (cnt >= ans) return;
    if (u == 1 && cnt != 0)
    {
        ans = min(ans, cnt);
        return;
    }
    for (auto [v, w] : g[u])
    {
        if (vis[v]) continue;
        vis[v] = true;
        dfs(v, cnt + w);
        vis[v] = false; // Backtrack
    }
}

signed main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w}); // Assuming undirected graph
    }
    dfs(1, 0);
    if (ans != INT_MAX) cout << ans;
    else cout << -1;
    return 0;
}