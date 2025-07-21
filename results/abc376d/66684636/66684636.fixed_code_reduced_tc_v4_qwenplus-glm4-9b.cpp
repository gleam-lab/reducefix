#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 5;

bool vis[N];
vector <int> g[N];
int n, m, ans = -1; // Change initialization to -1 as we are looking for the minimum path length

void dfs(int u, int cnt)
{
    vis[u] = true;
    if (cnt > ans) return; // Change condition to 'cnt > ans' to ensure we stop if we've already found a shorter path
    if (u == 1) 
    {
        ans = cnt; // Update ans when we reach node 1, without need for a separate check
        return;
    }
    for (int v : g[u])
    {
        if (!vis[v]) // Ensure we only visit unvisited nodes
            dfs(v, cnt + 1);
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
    dfs(1, 0);
    if (ans == -1) cout << -1; // Check if ans is still -1, which means no path was found
    else cout << ans;
    return 0;
}