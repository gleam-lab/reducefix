#include <bits/stdc++.h>
using namespace std;

int parent[200005];
vector<int> adj[200005];

void find_root(int v) {
    if (parent[v] == v)
        return;
    parent[v] = find_root(parent[v]);
}

void union_vertices(int u, int v) {
    find_root(u);
    find_root(v);
    if (parent[u] < parent[v])
        parent[v] = parent[u];
    else
        parent[u] = parent[v];
}

int kth_largest_in_component(int root, int k) {
    int size = adj[root].size();
    if (size < k) return -1;
    sort(adj[root].rbegin(), adj[root].rend());
    return adj[root][k - 1];
}

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
    }

    while (q--) {
        int op, u, v, k;
        cin >> op >> u >> v;
        if (op == 1) {
            union_vertices(u, v);
        } else if (op == 2) {
            // Find the root of vertex v
            int root_v = find_root(v);
            // Get the k-th largest vertex from the adjacency list rooted at vertex v
            cout << kth_largest_in_component(root_v, k) << endl;
        }
    }

    return 0;
}