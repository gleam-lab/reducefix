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
	if (u == 1 && cnt != 0)
	{
		ans = min(ans, cnt);
		return;
	}
	for (int v : g[u])
	{
		if (v != 1 && vis[v])	continue;
		dfs (v, cnt + 1);
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
	if (ans != (int)1e18)	cout << ans;
	else	cout << -1;
	return 0;
} 