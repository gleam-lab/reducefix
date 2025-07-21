#include <algorithm>
#include <iostream>
#include <cstdio>
#include <bitset>
using namespace std;

struct edge {
    int next, to;
} e[200001];

int n, m, head[200001], cnt;
bitset<200001> visited;
int dist[200001];

inline int read() {
    int res = 0;
    char c = getchar();
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9') res = (res << 1) + (res << 3) + (c ^ 48), c = getchar();
    return res;
}

inline void add(int u, int v) {
    e[++cnt].next = head[u];
    e[cnt].to = v;
    head[u] = cnt;
}

void dfs(int u, int dep) {
    if (u == 1 && dep == 0) {
        dist[1] = dep;
        return;
    }
    visited[u] = 1;
    for (int i = head[u], v; i; i = e[i].next) {
        v = e[i].to;
        if (!visited[v] || v == 1) {
            dist[v] = dep;
            dfs(v, dep + 1);
        }
    }
    return;
}

int main() {
    n = read(); m = read();
    for (int i = 1; i <= n; ++i) dist[i] = 100000000;
    for (int i = 1, u, v; i <= m; ++i) {
        u = read(); v = read();
        add(u, v);
        add(v, u); // Assuming the graph is undirected
    }
    dfs(1, 0);
    if (dist[1] == 100000000) printf("-1");
    else printf("%d", dist[1]);
}