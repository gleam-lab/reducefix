#include <algorithm>
#include <iostream>
#include <cstdio>
#include <queue>
#include <bitset>
using namespace std;

struct edge
{
    int next, to;
} a[200001];
int n, m, head[200001], cnt;
int dist[200001];
const int INF = 1e9;

inline int read()
{
    int res = 0;
    char c = getchar();
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9') res = (res << 1) + (res << 3) + (c ^ 48), c = getchar();
    return res;
}

inline void add(int u, int v)
{
    a[++cnt].next = head[u];
    a[cnt].to = v;
    head[u] = cnt;
}

int main()
{
    n = read(); m = read();
    
    for (int i = 1; i <= n; ++i) dist[i] = INF;
    
    for (int i = 1; i <= m; ++i)
    {
        int u = read(), v = read();
        add(u, v);
    }

    queue<int> q;
    bitset<200001> inQueue;
    
    // Start from node 1
    dist[1] = 0;
    q.push(1);
    inQueue[1] = true;

    while (!q.empty())
    {
        int u = q.front(); q.pop();
        inQueue[u] = false;

        for (int i = head[u]; i; i = a[i].next)
        {
            int v = a[i].to;
            if (dist[v] > dist[u] + 1)
            {
                dist[v] = dist[u] + 1;
                if (!inQueue[v])
                {
                    q.push(v);
                    inQueue[v] = true;
                }
            }
        }
    }

    if (dist[n] == INF) cout << -1;
    else cout << dist[n];
}