#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 5;

bool vis[N];
vector <int> g[N];
int n, m, ans = 1e18;

void dfs(int u, int cnt)
{
    vis[u] = true;
    if (cnt >= ans) return;
    for (int v : g[u])
    {
        if (!vis[v])
        {
            dfs(v, cnt + 1);
        }
    }
    vis[u] = false; // Reset the visited flag after DFS
}

void get_min_path()
{
    for (int i = 1; i <= n; i++)
    {
        vis[i] = false;
        dfs(i, 0);
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
        g[v].push_back(u); // Assuming undirected graph
    }
    get_min_path();
    if (ans != 1e18)
        cout << ans;
    else
        cout << -1;
    return 0;
}