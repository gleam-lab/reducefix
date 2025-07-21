#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 5;

vector<int> g[N];
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

    // To find the shortest cycle that starts and ends at node 1,
    // we can perform BFS from node 1 and look for the first return to node 1.
    vector<bool> vis(n + 1, false);
    queue<pair<int, int>> q;  // {node, distance}
    q.push({1, 0});
    vis[1] = true;

    while (!q.empty())
    {
        auto [u, d] = q.front();
        q.pop();

        for (int v : g[u])
        {
            if (v == 1)
            {
                cout << d + 1;
                return 0;
            }
            if (!vis[v])
            {
                vis[v] = true;
                q.push({v, d + 1});
            }
        }
    }

    cout << -1;
    return 0;
}