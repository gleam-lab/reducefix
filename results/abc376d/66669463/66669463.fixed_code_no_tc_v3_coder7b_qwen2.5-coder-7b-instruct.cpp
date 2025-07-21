#include<algorithm>
#include<iostream>
#include<cstdio>
#include<bitset>
using namespace std;

const int MAXN = 2 * 1e5 + 10;
struct Edge {
    int next, to;
} e[MAXN << 1];

int head[MAXN], cnt, ans[MAXN], n, m;
bitset<MAXN> visited;

int read() {
    int x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') { if(ch == '-') f = -1; ch = getchar(); }
    while(ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f;
}

void add(int u, int v) {
    e[++cnt].next = head[u];
    e[cnt].to = v;
    head[u] = cnt;
}

bool dfs(int u, int dep) {
    if (visited[u]) return true; // Cycle detected
    if (u == 1 && dep != 0) { // Found a cycle containing vertex 1
        ans[1] = min(ans[1], dep);
        return false;
    }
    visited[u] = true;
    for (int i = head[u]; ~i; i = e[i].next) {
        int v = e[i].to;
        if (!visited[v] && !dfs(v, dep + 1)) return false;
    }
    visited[u] = false;
    return true;
}

int main() {
    n = read(), m = read();
    memset(head, -1, sizeof(head));
    for (int i = 1; i <= n; ++i) ans[i] = INT_MAX;
    for (int i = 1, u, v; i <= m; ++i) u = read(), v = read(), add(u, v);
    
    bool foundCycle = false;
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            if (dfs(i, 0)) foundCycle = true;
        }
    }
    
    if (foundCycle) cout << ans[1] << endl;
    else cout << "-1" << endl;
    
    return 0;
}