#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 5;

bool vis[N];
vector <int> g[N];
int n, m;
int ans = 1e18;  // Use 'int' instead of 'long long' to match the expected return type

void dfs(int u, int cnt)
{
    vis[u] = true;
    if (cnt >= ans) return;  // Prune the search if the path length is already greater than the answer
    if (u == 1)
    {
        ans = min(ans, cnt);  // Update ans to be the minimum of the current answer and the current path length
        return;
    }
    for (int v : g[u])
    {
        if (v != 1 && vis[v]) continue;  // Skip already visited nodes except node 1
        dfs(v, cnt + 1);  // Continue DFS with path length incremented by 1
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
        g[v].push_back(u);  // Assuming undirected graph, add both directions
    }
    dfs(1, 0);  // Start DFS from node 1 with initial path length 0
    if (ans != (int)1e18) cout << ans;  // Print the answer if it was updated from the initial value
    else cout << -1;
    return 0;
}