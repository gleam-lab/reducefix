#include<bits/stdc++.h>
using namespace std;

vector<int> parent;
vector<vector<int>> tree;
vector<vector<pair<int, int>>> adj;
vector<vector<int>> vertices_longest_path;

int find_set(int v) {
    if (parent[v] != v) parent[v] = find_set(parent[v]);
    return parent[v];
}

void union_sets(int u, int v) {
    u = find_set(u);
    v = find_set(v);
    if (u != v) {
        parent[v] = u;
    }
}

void dfs(int v, int p) {
    for (auto& edge : adj[v]) {
        int to = edge.first;
        int weight = edge.second;
        if (to != p) {
            dfs(to, v);
            vertices_longest_path[v].push_back(weight);
        }
    }
}

void compute_longest_paths() {
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
    }
    dfs(0, -1);
    for (int i = 0; i < n; ++i) {
        vertices_longest_path[i].sort();
    }
    for (int i = 0; i < n; ++i) {
        int root = find_set(i);
        for (int j = 0; j < vertices_longest_path[i].size(); ++j) {
            adj[root].push_back({i, vertices_longest_path[i][j]});
        }
    }
}

int get_kth_largest_connected_vertex(int v, int k) {
    int root = find_set(v);
    if (k > adj[root].size()) return -1;
    return adj[root][adj[root].size() - k].first;
}

int main() {
    int n, q;
    cin >> n >> q;
    adj.resize(n);
    vertices_longest_path.resize(n);
    parent.resize(n);

    while (q--) {
        int type, u, v, k;
        cin >> type >> u >> v;
        if (type == 1) {
            if (find_set(u) != find_set(v)) {
                union_sets(u, v);
                adj[u].push_back({v, 1});
                adj[v].push_back({u, 1});
            }
        } else if (type == 2) {
            cout << get_kth_largest_connected_vertex(v - 1, k) + 1 << endl; // Convert 0-based index to 1-based index
        }
    }

    return 0;
}