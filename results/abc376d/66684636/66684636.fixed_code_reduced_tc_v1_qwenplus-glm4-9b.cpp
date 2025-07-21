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
    if (cnt >= ans)	return;
    if (cnt >= 2 && vis[1])
    {
        ans = min(ans, cnt);
    }
    for (int v : g[u])
    {
        if (v != 1 && !vis[v]) continue;
        dfs (v, cnt + 1);
    }    
}

void bfs()
{
    queue<int> q;
    q.push(1);
    vis[1] = true;
    int cnt = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : g[u])
        {
            if (!vis[v])
            {
                vis[v] = true;
                q.push(v);
            }
        }
        cnt++;
        if (cnt >= 2 && vis[1])
        {
            ans = min(ans, cnt);
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
        g[v].push_back(u);
    }
    dfs(1, 0);
    ans = min(ans, n - 1); // Maximum distance is n-1 if no path is found from 1
    if (ans != (int)1e18) cout << ans;
    else cout << -1;
    return 0;
}