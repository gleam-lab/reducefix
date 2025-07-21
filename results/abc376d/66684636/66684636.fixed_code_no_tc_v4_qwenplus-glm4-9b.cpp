#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 5;

bool vis[N];
vector <int> g[N];
int n, m;

void dfs(int u, int cnt)
{
    vis[u] = true;
    if (cnt > n) return;  // Ensure that we do not count more than n times
    if (u == 1 && cnt != 0)
    {
        // If we start from node 1 and we count u as 1, then we should not count it again
        // Hence we check if cnt is not 0 and set the minimum of the current answer
        ans = min(ans, cnt);
        return;
    }
    for (int v : g[u])
    {
        if (!vis[v])  // Use !vis[v] to check if v has not been visited
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
        g[v].push_back(u);  // Assuming the graph is undirected
    }
    int startNode = 1;  // Assuming we start from node 1
    dfs(startNode, 0);
    if (ans == INT_MAX) cout << -1;
    else cout << ans;
    return 0;
}