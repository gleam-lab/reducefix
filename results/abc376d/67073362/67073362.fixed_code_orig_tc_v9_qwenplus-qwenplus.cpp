#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define int long long

const int MAXN = 2e5 + 5;

int n, m;
vector<int> adj[MAXN];
int depth[MAXN];
bool visited[MAXN];
int ans = -1;

void dfs(int u, int d) {
    visited[u] = true;
    depth[u] = d;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v, d + 1);
        } else if (depth[v] != -1) {
            // Cycle detected
            int cycle_length = depth[u] - depth[v] + 1;
            if (ans == -1 || cycle_length < ans) {
                ans = cycle_length;
            }
        }
    }
    depth[u] = -1; // mark as no longer on the current path
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    memset(depth, -1, sizeof(depth));
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            dfs(i, 0);
        }
    }

    cout << ans << endl;
}
#undef int
int main() {
    IOS;
    solve();
    return 0;
}