#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 5;

vector<int> g[N];
int n, m, ans = -1;

void dfs(int u, int parent, int depth, map<int, int>& nodeDepth)
{
    nodeDepth[u] = depth;
    
    for (int v : g[u])
    {
        if (v == parent) continue;
        
        if (nodeDepth.find(v) != nodeDepth.end())
        {
            // Found a cycle
            int cycleLength = depth - nodeDepth[v] + 1;
            if (ans == -1 || cycleLength < ans)
                ans = cycleLength;
        }
        else
        {
            dfs(v, u, depth + 1, nodeDepth);
        }
    }
    
    nodeDepth.erase(u); // Remove from current path
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    
    map<int, int> nodeDepth;
    dfs(1, -1, 0, nodeDepth);
    
    cout << ans << "\n";
    return 0;
}