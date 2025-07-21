#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 5;

vector<int> g[N];
int n, m, ans = 1e18;

// BFS is more suitable for finding shortest cycle
int bfs()
{
    vector<int> dist(N, -1);
    queue<int> q;
    q.push(1);
    dist[1] = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : g[u])
        {
            if (dist[v] == -1)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
                // If we reach back to 1, return the cycle length
                if (v == 1)
                    return dist[v];
            }
            else if (v == 1 && dist[v] != 0)
            {
                // We found a cycle back to 1
                return dist[u] + 1;
            }
        }
    }
    return -1; // No cycle found
}

signed main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    cout << bfs();
    return 0;
}