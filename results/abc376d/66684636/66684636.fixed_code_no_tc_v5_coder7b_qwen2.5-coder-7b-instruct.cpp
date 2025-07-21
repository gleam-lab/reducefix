#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 5;

bool vis[N];
vector<int> g[N];
int n, m, ans = INT_MAX;

void dfs(int u, int cnt, int parent)
{
    vis[u] = true;
    if (cnt >= ans) return;
    if (u == 1 && cnt != 0)
    {
        ans = min(ans, cnt);
        return;
    }
    for (int v : g[u])
    {
        if (v == parent) continue; // Skip revisiting the immediate parent
        if (vis[v]) continue;
        dfs(v, cnt + 1, u); // Update the parent before recursive call
    }
}

signed main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    dfs(1, 0, -1); // Start DFS from node 1 with initial count as 0 and no parent (-1)
    if (ans != INT_MAX) cout << ans;
    else cout << -1;
    return 0;
}