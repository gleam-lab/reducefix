#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 5;

bool vis[N];
vector <int> g[N];
int n, m, ans = 1e18;

void dfs(int u, int cnt, vector<int>& path)
{
    path.push_back(u);
    vis[u] = true;
    if (u == 1 && cnt > 1)
    {
        ans = min(ans, cnt);
        return;
    }
    for (int v : g[u])
    {
        if (!vis[v])
            dfs(v, cnt + 1, path);
        else if (find(path.begin(), path.end(), v) != path.end())
        {
            int cycle_length = cnt - (find(path.begin(), path.end(), v) - path.begin()) + 1;
            ans = min(ans, cycle_length);
        }
    }   
    path.pop_back();
    vis[u] = false;
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
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
            dfs(i, 0, {});
    }
    if (ans != (int)1e18) cout << ans;
    else cout << -1;
    return 0;
}