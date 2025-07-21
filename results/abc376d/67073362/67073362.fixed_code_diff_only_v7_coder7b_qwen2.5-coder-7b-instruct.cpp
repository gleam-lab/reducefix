#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int MAXN = 2e5 + 10;
vector<int> adj[MAXN];
bool visited[MAXN];
int depth[MAXN];

void dfs(int node, int d) {
    visited[node] = true;
    depth[node] = d;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, d + 1);
        } else {
            if (depth[neighbor] != 0 && depth[neighbor] + d > depth[node]) {
                depth[node] = depth[neighbor] + d;
            }
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Assuming undirected graph
    }

    int min_depth = INT_MAX;
    for (int i = 1; i <= n; ++i) {
        fill(visited, visited + MAXN, false);
        fill(depth, depth + MAXN, 0);
        dfs(i, 1);
        for (int j = 1; j <= n; ++j) {
            min_depth = min(min_depth, depth[j]);
        }
    }

    if (min_depth == INT_MAX) cout << -1 << endl;
    else cout << min_depth << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}