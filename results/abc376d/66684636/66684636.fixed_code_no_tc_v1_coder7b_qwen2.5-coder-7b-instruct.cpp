#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 5;

bool vis[N];
vector<int> g[N];
int n, m, ans = INT_MAX;

void dfs(int u, int cnt, vector<bool>& recStack) {
    vis[u] = true;
    recStack[u] = true;
    
    for (int v : g[u]) {
        if (!vis[v]) {
            dfs(v, cnt + 1, recStack);
        } else if (recStack[v]) {
            ans = min(ans, cnt + 1);
        }
    }
    
    recStack[u] = false;
}

signed main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            vector<bool> recStack(n + 1, false);
            dfs(i, 0, recStack);
        }
    }
    
    if (ans == INT_MAX) cout << -1;
    else cout << ans;
    
    return 0;
}