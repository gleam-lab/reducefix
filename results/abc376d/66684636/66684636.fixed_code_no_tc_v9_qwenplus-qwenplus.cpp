#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 5;

vector<int> g[N];
int n, m, ans = -1;

void dfs(int u, int parent, int depth, int &minCycle)
{
    static vector<bool> inStack(N, false);
    static vector<int> discoveryTime(N, -1);
    static int time = 0;

    discoveryTime[u] = time++;
    inStack[u] = true;

    for (int v : g[u])
    {
        if (v == parent) continue; // Skip the parent node to avoid revisiting

        if (!discoveryTime[v])
        {
            dfs(v, u, depth + 1, minCycle);
        }
        else if (inStack[v])
        {
            // Back edge found a cycle
            int cycleLength = depth - discoveryTime[v] + 1;
            if (minCycle == -1 || cycleLength < minCycle)
                minCycle = cycleLength;
        }
    }

    inStack[u] = false;
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
        g[v].push_back(u); // Undirected graph
    }

    int minCycle = -1;
    vector<bool> visited(n + 1, false);

    for (int i = 1; i <= n; ++i)
    {
        if (!visited[i])
        {
            dfs(i, -1, 0, minCycle);
            visited[i] = true;
        }
    }

    cout << (minCycle != -1 ? minCycle : -1) << endl;
    return 0;
}