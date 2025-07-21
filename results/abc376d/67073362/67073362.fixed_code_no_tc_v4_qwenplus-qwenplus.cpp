#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 10, INF = 1e9 + 7;

vector<vector<int>> adj;
vector<bool> visited;
int min_cycle_length = INF;

void dfs(int u, int depth, vector<int>& recursion_stack) {
    recursion_stack[u] = depth;
    for (int v : adj[u]) {
        if (!visited[v]) {
            visited[v] = true;
            dfs(v, depth + 1, recursion_stack);
        } else if (recursion_stack[v] != -1) {
            // Found a back edge, potential cycle
            min_cycle_length = min(min_cycle_length, depth - recursion_stack[v] + 1);
        }
    }
    recursion_stack[u] = -1; // Remove from recursion stack
}

void solve() {
    int n, m;
    cin >> n >> m;
    adj.assign(n + 1, vector<int>());
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    visited.assign(n + 1, false);
    vector<int> recursion_stack(n + 1, -1);

    visited[1] = true;
    dfs(1, 0, recursion_stack);

    if (min_cycle_length == INF || min_cycle_length < 2)
        cout << -1;
    else
        cout << min_cycle_length;
}

signed main() {
    IOS;
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}