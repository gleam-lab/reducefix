#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 5;
const int INF = 1e18;

vector<int> g[N];
int dist[N];
int n, m;

signed main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    int ans = INF;
    queue<pair<int, int>> q;
    
    for (int v : g[1])
    {
        q.push({v, 1});
    }

    while (!q.empty())
    {
        auto [u, d] = q.front();
        q.pop();
        
        if (u == 1)
        {
            ans = d;
            break;
        }
        
        if (d >= ans) continue;
        
        for (int v : g[u])
        {
            if (d + 1 < ans)
            {
                q.push({v, d + 1});
            }
        }
    }

    if (ans != INF) cout << ans;
    else cout << -1;
    
    return 0;
}