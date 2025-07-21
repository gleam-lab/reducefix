#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 2e5 + 10, M = 2e6 + 10, INF = 1e9 + 7, P = 998244353;
vector<vector<int>> adj(N);

void dfs(int u, int p, vector<int>& depth, vector<int>& parent, int& mx_depth, int& farthest_node) {
    depth[u] = depth[p] + 1;
    if (depth[u] > mx_depth) {
        mx_depth = depth[u];
        farthest_node = u;
    }
    for (int v : adj[u]) {
        if (v != p) {
            parent[v] = u;
            dfs(v, u, depth, parent, mx_depth, farthest_node);
        }
    }
}

pair<int, int> find_diameter() {
    vector<int> depth(N), parent(N, -1);
    int mx_depth = 0, farthest_node = 0;
    dfs(1, -1, depth, parent, mx_depth, farthest_node);
    
    mx_depth = 0;
    dfs(farthest_node, -1, depth, parent, mx_depth, farthest_node);
    
    return {farthest_node, mx_depth};
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
    
    auto [farthest_node, diameter] = find_diameter();
    
    cout << diameter << '\n';
    
    return 0;
}