#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 5;

vector<int> g[N];
int n, m, ans = 1e18;

// BFS is better for finding shortest cycle
int bfs()
{
    vector<int> dist(n + 1, -1);
    queue<int> q;
    
    // Start from node 1
    dist[1] = 0;
    q.push(1);
    
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
            }
            else if (v != 1 && dist[v] != dist[u] + 1)
            {
                // Found a back edge forming a cycle
                return dist[u] + dist[v] + 1;
            }
        }
    }
    return -1;
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

    // Try to find the shortest cycle through node 1
    cout << bfs();
    
    return 0;
}