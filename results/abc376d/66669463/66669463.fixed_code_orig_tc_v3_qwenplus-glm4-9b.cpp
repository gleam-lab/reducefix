#include <bits/stdc++.h>
using namespace std;

struct edge {
    int next, to;
} a[200001];

int n, m, head[200001], cnt, ans[200001];
bitset<200001> visited;  // Use visited instead of bj

inline int read() {
    int res = 0, sign = 1;
    char c = getchar();
    if (c == '-') {
        sign = -1;
        c = getchar();
    }
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9') res = res * 10 + (c - '0'), c = getchar();
    return sign * res;
}

void add(int u, int v) {
    a[++cnt].next = head[u];
    a[cnt].to = v;
    head[u] = cnt;
    // If the graph is undirected, add the reverse edge
    a[++cnt].next = head[v];
    a[cnt].to = u;
    head[v] = cnt;
}

void dfs(int u, int dep) {
    if (ans[u] < dep) return;  // Only proceed if this path gives a shorter answer
    visited[u] = 1;
    for (int i = head[u], v; i; i = a[i].next) {
        v = a[i].to;
        if (!visited[v]) {
            ans[v] = dep + 1;
            dfs(v, dep + 1);
        }
    }
}

int main() {
    n = read(); m = read();
    for (int i = 1; i <= n; ++i) ans[i] = 100000000;
    for (int i = 1, u, v; i <= m; ++i) u = read(), v = read(), add(u, v);
    dfs(1, 0);
    if (ans[1] == 100000000) printf("-1\n");
    else printf("%d\n", ans[1]);
}