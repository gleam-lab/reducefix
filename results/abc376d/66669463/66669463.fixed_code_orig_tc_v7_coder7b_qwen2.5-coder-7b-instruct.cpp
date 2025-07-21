#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

const int MAXN = 200005;

vector<int> adj[MAXN];
bool visited[MAXN];
int depth[MAXN];

void dfs(int node, int parent, int d) {
    visited[node] = true;
    depth[node] = d;
    for (int child : adj[node]) {
        if (child != parent && !visited[child]) {
            dfs(child, node, d + 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1, 0);

    int min_depth = INT_MAX;
    for (int i = 1; i <= n; ++i) {
        min_depth = min(min_depth, depth[i]);
    }

    cout << min_depth << endl;

    return 0;
}