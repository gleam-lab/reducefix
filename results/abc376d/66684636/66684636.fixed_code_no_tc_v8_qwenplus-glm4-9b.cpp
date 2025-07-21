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
    cnt++;  // Increment count as we visit each node
    if (cnt >= ans) return;  // Early stopping if count exceeds current answer
    if (u == 1 && cnt >= 2) {  // Check if the path from 1 requires at least 2 edges
        ans = min(ans, cnt - 1);  // Subtract 1 as we need at least one more edge to return to 1
        return;
    }
    for (int v : g[u]) {
        if (!vis[v]) {  // Visit only unvisited nodes
            dfs(v, cnt);  // Pass current count to the recursive call
        }
    }
}

signed main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);  // Add bidirectional edges
    }
    dfs(1, 0);
    if (ans == 1e18) cout << -1;  // If no valid path found, output -1
    else cout << ans;
    return 0;
}