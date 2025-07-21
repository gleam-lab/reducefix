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
    if (u == 1) 
    {
        ans = min(ans, cnt); // Update answer with the shortest path found so far
        return;
    }
    for (int v : g[u])
    {
        if (!vis[v]) 
        {
            dfs(v, cnt + 1); // Continue DFS if the node hasn't been visited
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
        g[v].push_back(u); // Since the graph is undirected, add an edge in both directions
    }
    // Start DFS from every node
    for (int i = 1; i <= n; i++)
    {
        dfs(i, 0);
        vis[i] = false; // Reset visited nodes for a new DFS from another unvisited node
    }
    if (ans != (int)1e18) 
        cout << ans;
    else 
        cout << -1;
    return 0;
}