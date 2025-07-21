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

int n, m, head[200001], cnt, dist[200001];
bitset<200001> in_queue;

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

void bfs()
{
    queue<int> q;
    fill(dist, dist + n + 1, 100000000);
    
    dist[1] = 0;
    q.push(1);
    in_queue[1] = 1;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        in_queue[u] = 0;
        
        for (int i = head[u]; i; i = a[i].next) {
            int v = a[i].to;
            if (dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                if (!in_queue[v]) {
                    q.push(v);
                    in_queue[v] = 1;
                }
            }
        }
    }
}

int main()
{
    n = read(); m = read();
    
    for (int i = 1; i <= m; ++i) {
        int u = read(), v = read();
        add(u, v);
    }
    
    bfs();
    
    if (dist[1] == 100000000)
        printf("-1");
    else
        printf("%d", dist[1]);
}