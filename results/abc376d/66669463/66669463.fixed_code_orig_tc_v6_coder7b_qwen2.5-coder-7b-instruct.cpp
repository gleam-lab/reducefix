#include<algorithm>
#include<iostream>
#include<cstdio>
#include<bitset>
using namespace std;

const int MAXN = 2e5 + 10;
struct Edge {
    int next, to;
} e[MAXN << 1];

int head[MAXN], cnt, ans[MAXN], n, m;
bitset<MAXN> visited;

inline int read() {
    int x = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9') ch = getchar();
    while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
    return x;
}

inline void add(int u, int v) {
    e[++cnt].next = head[u];
    e[cnt].to = v;
    head[u] = cnt;
}

void dfs(int u, int depth) {
    if (u == 1 && depth != 0) {
        ans[1] = min(ans[1], depth);
        return;
    }
    visited[u] = true;
    for (int i = head[u]; i; i = e[i].next) {
        int v = e[i].to;
        if (!visited[v] || v == 1) {
            if (depth + 1 < ans[v]) {
                ans[v] = depth + 1;
                dfs(v, depth + 1);
            }
        }
    }
    return;
}

int main() {
    n = read(), m = read();
    memset(ans, 0x3f, sizeof ans);
    for (int i = 1; i <= m; ++i) {
        int u = read(), v = read();
        add(u, v);
        add(v, u); // Assuming undirected graph
    }
    dfs(1, 0);
    if (ans[1] == 0x3f3f3f3f) printf("-1\n");
    else printf("%d\n", ans[1]);
    return 0;
}