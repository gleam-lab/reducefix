#include <bits/stdc++.h>
using namespace std;

struct edge {
    int to;
} a[200001];

int n, m, head[200001], cnt;
int ans[200001];
vector<int> adj[200001];

inline int read() {
    int res = 0;
    char c = getchar();
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9') res = (res << 1) + (res << 3) + (c ^ 48), c = getchar();
    return res;
}

void add(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u); // Ensure bidirectional edges for bidirectional tree or graph
}

void dfs(int u, int dep) {
    if (u == 1 && dep)
        ans[1] = min(ans[1], dep);
    for (int v : adj[u]) {
        if (dep + 1 < ans[v]) {
            ans[v] = dep + 1;
            dfs(v, dep + 1);
        }
    }
}

int main() {
    n = read(); m = read();
    for (int i = 1; i <= n; ++i) ans[i] = 100000000;
    for (int i = 1, u, v; i <= m; ++i) {
        u = read(); v = read();
        add(u, v);
    }
    dfs(1, 0);
    if (ans[1] == 100000000) cout << "-1";
    else cout << ans[1];
}