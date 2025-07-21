#include<algorithm>
#include<iostream>
#include<cstdio>
#include<bitset>
using namespace std;
struct edge {
    int next, to;
} a[2 * 100001];
int n, m, head[2 * 100001], cnt, ans = INT_MAX;
bitset<2 * 100001> visited;

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

bool dfs(const int u, const int dep) {
    if (visited[u] == true) {
        if (u == 1) ans = min(ans, dep);
        return false;
    }
    visited[u] = true;
    for (int i = head[u], v; i; i = a[i].next) {
        v = a[i].to;
        if (!dfs(v, dep + 1)) return false;
    }
    visited[u] = false;
    return true;
}

int main() {
    n = read(); m = read();
    for (int i = 1; i <= n; ++i) visited[i] = false;
    for (int i = 1, u, v; i <= m; ++i) u = read(), v = read(), add(u, v);
    dfs(1, 0);
    if (ans == INT_MAX) printf("-1\n");
    else printf("%d\n", ans);
}