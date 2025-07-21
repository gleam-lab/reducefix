#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, q;
vector<int> parent, size;
vector<vector<int>> adj;

int find_set(int v) {
    if (parent[v] != v)
        parent[v] = find_set(parent[v]);
    return parent[v];
}

void union_set(int u, int v) {
    int root_u = find_set(u);
    int root_v = find_set(v);
    if (root_u != root_v) {
        if (size[root_u] < size[root_v]) {
            parent[root_u] = root_v;
            size[root_v] += size[root_u];
            adj[root_v].insert(adj[root_v].end(), adj[root_u].begin(), adj[root_u].end());
        } else {
            parent[root_v] = root_u;
            size[root_u] += size[root_v];
            adj[root_u].insert(adj[root_u].end(), adj[root_v].begin(), adj[root_v].end());
        }
    }
}

int main() {
    cin >> n >> q;
    parent.resize(n + 1);
    size.resize(n + 1, 1);
    adj.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < q; i++) {
        int op, u, v;
        cin >> op >> u >> v;
        if (op == 1) {
            union_set(u, v);
        } else {
            int root_v = find_set(v);
            sort(adj[root_v].begin(), adj[root_v].end(), greater<int>());
            if (k <= adj[root_v].size()) {
                cout << adj[root_v][k - 1] << endl;
            } else {
                cout << -1 << endl;
            }
        }
    }

    return 0;
}