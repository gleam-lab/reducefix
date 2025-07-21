#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 5;

bool vis[N];
vector <int> g[N];
int n, m, ans = 1e18;

void dfs(int u, int depth)
{
    vis[u] = true;
    for (int v : g[u])
    {
        if (!vis[v]) // If v has not been visited
        {
            dfs(v, depth + 1);
            // Update the answer with the minimum depth found
            ans = min(ans, depth);
        }
    }
    vis[u] = false; // Unmark the node to allow other DFS calls to visit it
}

signed main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u); // Ensure the graph is undirected
    }
    dfs(1, 0);
    if (ans == 1e18) cout << -1; // No path found
    else cout << ans;
    return 0;
}