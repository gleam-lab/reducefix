#include<algorithm>
#include<iostream>
#include<cstdio>
#include<bitset>
using namespace std;

const int MAXN = 2e5 + 10;
struct Edge {
    int next, to;
} edges[MAXN << 1];

int head[MAXN], cnt, ans[MAXN], deg[MAXN];
bitset<MAXN> visited;

inline int read() {
    int res = 0;
    char c = getchar();
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9') res = (res << 1) + (res << 3) + (c ^ 48), c = getchar();
    return res;
}

inline void add(int u, int v) {
    edges[++cnt].next = head[u];
    edges[cnt].to = v;
    head[u] = cnt;
    ++deg[v];
}

bool dfs(int u, int depth) {
    if (u == 1 && depth != 0) {
        ans[1] = min(ans[1], depth);
        return true;
    }
    visited[u] = true;
    for (int i = head[u], v; i; i = edges[i].next) {
        v = edges[i].to;
        if (!visited[v] || v == 1) {
            if (dfs(v, depth + 1)) return true;
        }
    }
    visited[u] = false;
    return false;
}

int main() {
    n = read(), m = read();
    for (int i = 1; i <= n; ++i) ans[i] = 100000000, deg[i] = 0;
    for (int i = 1, u, v; i <= m; ++i) u = read(), v = read(), add(u, v);

    for (int i = 1; i <= n; ++i) {
        if (!deg[i] && !visited[i]) {
            dfs(i, 0);
        }
    }

    if (ans[1] == 100000000) printf("-1\n");
    else printf("%d\n", ans[1]);

    return 0;
}