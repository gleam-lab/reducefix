#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 5;

bool vis[N];
vector <int> g[N];
int n, m;

void dfs(int u, int depth, int &max_depth)
{
    vis[u] = true;
    if (depth > max_depth) max_depth = depth;
    for (int v : g[u])
        if (!vis[v])
            dfs(v, depth + 1, max_depth);
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
    int max_depth = 0;
    dfs(1, 0, max_depth);
    cout << max_depth;
    return 0;
}