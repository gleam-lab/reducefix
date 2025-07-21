#include <algorithm>
#include <iostream>
#include <cstdio>
#include <bitset>
using namespace std;

struct edge {
    int next, to;
} a[200001];

int n, m, head[200001], cnt, ans[200001];
bitset<200001> visited;

inline int read() {
    int res = 0;
    char c = getchar();
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9') res = (res << 1) + (res << 3) + (c ^ 48), c = getchar();
    return res;
}

inline void add(const int u, const int v) {
    a[++cnt].next = head[u];
    a[cnt].to = v;
    head[u] = cnt;
}

void dfs(const int u, const int dep) {
    if (u == 1 && dep) {
        ans[1] = min(ans[1], dep);
        return;
    }
    visited[u] = true;
    for (int i = head[u], v; i; i = a[i].next) {
        v = a[i].to;
        if (!visited[v] || v == 1) {
            ans[v] = dep + 1;
            dfs(v, dep + 1);
        }
    }
    return;
}

int main() {
    n = read(); m = read();
    for (int i = 1; i <= n; ++i) ans[i] = 100000000;
    for (int i = 1, u, v; i <= m; ++i) u = read(), v = read(), add(u, v);
    dfs(1, 0);
    if (ans[1] == 100000000) printf("-1");
    else printf("%d", ans[1]);
}