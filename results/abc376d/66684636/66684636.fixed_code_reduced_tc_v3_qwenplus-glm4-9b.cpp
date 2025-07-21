#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 5;

vector<int> g[N];
int n, m, ans = 1e18;

void dfs(int u, int cnt)
{
    if (cnt >= ans) return;
    if (cnt > 0) {
        ans = min(ans, cnt);
    }
    for (int v : g[u])
    {
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
    if (ans == 1e18) cout << -1;
    else cout << ans;
    return 0;
}