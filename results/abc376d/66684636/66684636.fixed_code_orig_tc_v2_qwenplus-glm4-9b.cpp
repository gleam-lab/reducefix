#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 5;

bool vis[N];
vector <int> g[N];
int n, m, ans = 1e18;
int component_size = 0;

void dfs(int u, int parent)
{
    vis[u] = true;
    component_size++;

    for (int v : g[u])
    {
        if (v == parent) continue;
        if (!vis[v])
            dfs(v, u);
        else
            // If a cycle is detected, break
            return;
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    // Start DFS from node 1
    dfs(1, -1);

    // Check if there's only one connected component
    if (component_size != n)
    {
        cout << -1;
        return 0;
    }

    // Calculate the minimum number of edges to be added
    ans = n - 1;
    cout << ans;
    return 0;
}