#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 5;

bool vis[N];
vector <int> g[N];
int n, m, ans = 0;

void dfs(int u, int cnt)
{
    vis[u] = true;
    if (cnt >= ans) 
        return; // Prune to avoid unnecessary deeper searching
    for (int v : g[u])
    {
        if (!vis[v]) // Check if v is not visited to avoid cycles
        {
            dfs(v, cnt + 1);
        }
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
        g[v].push_back(u); // Ensure the graph is undirected
    }
    dfs(1, 0);
    if (ans == 0) cout << -1; // If no valid path found
    else cout << ans;
    return 0;
}