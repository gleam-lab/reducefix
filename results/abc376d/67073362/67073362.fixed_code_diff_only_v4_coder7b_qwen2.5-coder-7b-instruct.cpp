#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int MAXN = 2e5 + 10;

vector<int> adj[MAXN];
bool visited[MAXN];

int dfs(int node, int depth) {
    visited[node] = true;
    int min_depth = depth;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            int sub_depth = dfs(neighbor, depth + 1);
            min_depth = min(min_depth, sub_depth);
        }
    }
    return min_depth;
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    int min_dist = INT_MAX;
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            int dist = dfs(i, 0);
            min_dist = min(min_dist, dist);
        }
    }

    if (min_dist == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << min_dist << endl;
    }
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