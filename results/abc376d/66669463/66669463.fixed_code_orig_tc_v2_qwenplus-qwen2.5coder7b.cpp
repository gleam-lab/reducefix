#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 200001;

vector<int> adj[MAXN];
int n, m, ans = INT_MAX;

void dfs(int u, int d, vector<bool>& visited) {
    if (u == 1 && d != 0) {
        ans = min(ans, d);
        return;
    }
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v] || v == 1) {
            dfs(v, d + 1, visited);
        }
    }
    visited[u] = false;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> visited(n + 1, false);
    dfs(1, 0, visited);
    if (ans == INT_MAX) cout << "-1" << endl;
    else cout << ans << endl;
    return 0;
}