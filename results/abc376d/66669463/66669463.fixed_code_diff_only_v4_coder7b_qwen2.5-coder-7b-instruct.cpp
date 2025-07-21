#include<algorithm>
#include<iostream>
#include<cstdio>
#include<bitset>
using namespace std;

const int MAXN = 200001;

struct Edge {
    int next, to;
};

Edge edges[MAXN * 2]; // Double the size to handle undirected graph properly
int head[MAXN], cnt, ans[MAXN];
bitset<MAXN> visited;

int read() {
    int res = 0;
    char c = getchar();
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9') res = (res << 1) + (res << 3) + (c ^ 48), c = getchar();
    return res;
}

void add(int u, int v) {
    edges[++cnt].next = head[u];
    edges[cnt].to = v;
    head[u] = cnt;
    edges[++cnt].next = head[v];
    edges[cnt].to = u; // Add this line for an undirected graph
    head[v] = cnt;
}

void dfs(int u, int depth) {
    if (u == 1 && depth) {
        ans[1] = min(ans[1], depth);
        return;
    }
    visited[u] = true;
    for (int i = head[u], v; i != -1; i = edges[i].next) {
        v = edges[i].to;
        if (!visited[v] || v == 1) {
            if (depth + 1 < ans[v]) {
                ans[v] = depth + 1;
                dfs(v, depth + 1);
            }
        }
    }
    visited[u] = false; // Reset visited status after visiting all neighbors
}

int main() {
    n = read(), m = read();
    fill(head, head + n + 1, -1); // Initialize head array with -1
    fill(ans, ans + n + 1, INT_MAX); // Initialize ans array with infinity
    for (int i = 1; i <= m; ++i) {
        int u = read(), v = read();
        add(u, v);
    }
    dfs(1, 0);
    if (ans[1] == INT_MAX) printf("-1");
    else printf("%d", ans[1]);
    return 0;
}