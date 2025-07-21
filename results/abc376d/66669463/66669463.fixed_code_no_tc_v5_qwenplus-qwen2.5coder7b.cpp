#include <algorithm>
#include <iostream>
#include <cstdio>
#include <bitset>
using namespace std;

const int MAXN = 200001;

struct Edge {
    int next, to;
};

Edge a[MAXN * 2];
int n, m, head[MAXN], cnt, ans[MAXN];
bitset<MAXN> visited;

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

void dfs(const int u, const int depth) {
    if (u == 1 && depth) {
        ans[1] = min(ans[1], depth);
        return;
    }
    visited[u] = true;
    for (int i = head[u], v; i; i = a[i].next) {
        v = a[i].to;
        if (!visited[v] || v == 1) {
            if (depth + 1 < ans[v]) {
                ans[v] = depth + 1;
                dfs(v, depth + 1);
            }
        }
    }
    visited[u] = false;
}

int main() {
    n = read();
    m = read();
    for (int i = 1; i <= n; ++i) ans[i] = 100000000;
    for (int i = 1, u, v; i <= m; ++i) {
        u = read();
        v = read();
        add(u, v);
        add(v, u); // Add reverse edge for undirected graph
    }
    dfs(1, 0);
    if (ans[1] == 100000000) printf("-1");
    else printf("%d\n", ans[1]);
    return 0;
}