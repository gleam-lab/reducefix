#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 5;

bool vis[N], in_stack[N];
vector<int> g[N];
int n, m, ans = INT_MAX;

void dfs(int u, int cnt) {
    vis[u] = true;
    in_stack[u] = true;
    for (int v : g[u]) {
        if (!vis[v]) {
            dfs(v, cnt + 1);
        } else if (in_stack[v]) {
            ans = min(ans, cnt - (vis[v] ? 0 : 1));
        }
    }
    in_stack[u] = false;
}

signed main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    dfs(1, 0);
    if (ans != INT_MAX) cout << ans;
    else cout << -1;
    return 0;
}