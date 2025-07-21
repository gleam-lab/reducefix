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
    if (cnt >= ans)	return;
    if (cnt > 0)	// since we are not counting the root node (1) as a valid path
    {
        ans = min(ans, cnt);
    }
    for (int v : g[u])
    {
        if (!vis[v])	// to avoid revisiting nodes
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
    }
    dfs(1, 0);
    if (ans == 0) cout << -1;
    else cout << ans;
    return 0;
}