#include <bits/stdc++.h>
using namespace std;

struct edge {
    int next, to;
} a[200001];

int n, m, head[200001], cnt, ans[200001];
bool visited[200001];
vector<int> adj[200001];

inline int read() {
    int res = 0;
    char c = getchar();
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9') res = (res * 10) + (c - '0'), c = getchar();
    return res;
}

void add(int u, int v) {
    adj[u].push_back(v);
}

void dfs(int u, int dep) {
    if (visited[u]) {
        if (dep < ans[u]) {
            ans[u] = dep;
        }
        return;
    }
    visited[u] = true;
    for (int v : adj[u]) {
        dfs(v, dep + 1);
    }
}

int main() {
    n = read(); m = read();
    for (int i = 1; i <= n; ++i) ans[i] = 1e8;
    for (int i = 1, u, v; i <= m; ++i) {
        u = read(); v = read();
        add(u, v);
        add(v, u);
    }
    memset(visited, false, sizeof(visited));
    dfs(1, 0);
    if (ans[1] == 1e8) cout << "-1";
    else cout << ans[1];
}