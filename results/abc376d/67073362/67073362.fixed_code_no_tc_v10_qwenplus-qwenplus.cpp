#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10, INF = 1e9 + 7;

vector<vector<int>> graph(N);
vector<bool> visited(N);
int min_cycle_length = INF;

void dfs(int u, int depth, vector<int>& path_vis) {
    path_vis[u] = true;
    for (int v : graph[u]) {
        if (!path_vis[v]) {
            dfs(v, depth + 1, path_vis);
        } else if (v == 1 && depth >= 1) {  // Ensure it's a valid cycle back to node 1
            min_cycle_length = min(min_cycle_length, depth + 1);
        }
    }
    path_vis[u] = false;
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    vector<int> path_vis(n + 1, false);
    dfs(1, 0, path_vis);

    cout << (min_cycle_length == INF ? -1 : min_cycle_length) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();

    return 0;
}