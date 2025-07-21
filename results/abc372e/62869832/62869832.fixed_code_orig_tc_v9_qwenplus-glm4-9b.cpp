#include<bits/stdc++.h>
using namespace std;
vector<int> parent;
vector<vector<int>> rank;
vector<vector<int>> adj;

int find_set(int v) {
    if (parent[v] != v) {
        parent[v] = find_set(parent[v]);
    }
    return parent[v];
}

void union_set(int u, int v) {
    int root_u = find_set(u);
    int root_v = find_set(v);

    if (root_u != root_v) {
        if (rank[root_u] > rank[root_v]) {
            parent[root_v] = root_u;
            adj[root_u].insert(adj[root_u].end(), adj[root_v].begin(), adj[root_v].end());
        } else if (rank[root_u] < rank[root_v]) {
            parent[root_u] = root_v;
            adj[root_v].insert(adj[root_v].end(), adj[root_u].begin(), adj[root_u].end());
        } else {
            parent[root_v] = root_u;
            rank[root_u]++;
            adj[root_u].insert(adj[root_u].end(), adj[root_v].begin(), adj[root_v].end());
        }
    }
}

int main() {
    int n, q;
    cin >> n >> q;

    parent.resize(n + 1);
    rank.resize(n + 1);
    adj.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        rank[i] = 0;
        adj[i] = vector<int>(1, i);
    }

    for (int i = 0; i < q; i++) {
        int op, u, v;
        cin >> op >> u >> v;

        if (op == 1) { // Add edge
            union_set(u, v);
        } else if (op == 2) { // Query
            int root_v = find_set(v);
            vector<int> components = adj[root_v];
            sort(components.begin(), components.end(), greater<int>());

            int k;
            cin >> k;
            if (k > components.size()) {
                cout << -1 << '\n';
            } else {
                cout << components[k - 1] << '\n';
            }
        }
    }

    return 0;
}