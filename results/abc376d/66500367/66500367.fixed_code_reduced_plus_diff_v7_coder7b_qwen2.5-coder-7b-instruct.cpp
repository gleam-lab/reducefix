#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
vector<int> adj[MAXN];
int depth[MAXN], parent[MAXN];

void bfs(int start) {
    queue<int> q;
    q.push(start);
    depth[start] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (depth[v] == 0) {
                depth[v] = depth[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }
}

int findLCA(int u, int v) {
    if (depth[u] > depth[v]) swap(u, v);
    for (int i = 19; i >= 0; --i) {
        if ((depth[v] - depth[u]) & (1 << i)) {
            v = parent[v][i];
        }
    }
    if (u == v) return u;
    for (int i = 19; i >= 0; --i) {
        if (parent[u][i] != parent[v][i]) {
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return parent[u][0];
}

int solve(int n, vector<pair<int, int>>& edges) {
    for (auto [u, v] : edges) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    bfs(1);
    
    for (int i = 2; i <= n; ++i) {
        parent[i][0] = parent[parent[i][0]][0];
        for (int j = 1; j <= 19; ++j) {
            parent[i][j] = parent[parent[i][j - 1]][j - 1];
        }
    }

    int max_dist = 0;
    for (auto [u, v] : edges) {
        int lca = findLCA(u, v);
        int dist = depth[u] + depth[v] - 2 * depth[lca];
        max_dist = max(max_dist, dist);
    }
    return max_dist;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].first >> edges[i].second;
    }

    cout << solve(n, edges) << '\n';

    return 0;
}