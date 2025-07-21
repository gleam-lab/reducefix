#include<bits/stdc++.h>
using namespace std;
int parent[200005];
int size[200005];
int rank[200005];
int subsize[200005][60]; // k-th largest vertex number for each vertex

void union_set(int u, int v) {
    int root_u = find_set(u);
    int root_v = find_set(v);

    if (root_u != root_v) {
        // Union by rank
        if (rank[root_u] > rank[root_v]) {
            parent[root_v] = root_u;
            size[root_u] += size[root_v];
            subsize[root_u][0] = subsize[root_v][5]; // k=5 is the largest by default
            for (int k = 1; k < 60; ++k) {
                subsize[root_u][k] = subsize[root_v][k - 1];
            }
        } else if (rank[root_u] < rank[root_v]) {
            parent[root_u] = root_v;
            size[root_v] += size[root_u];
            subsize[root_v][0] = subsize[root_u][5]; // k=5 is the largest by default
            for (int k = 1; k < 60; ++k) {
                subsize[root_v][k] = subsize[root_u][k - 1];
            }
        } else {
            parent[root_v] = root_u;
            size[root_u] += size[root_v];
            rank[root_u] += 1;
            subsize[root_u][0] = subsize[root_v][5]; // k=5 is the largest by default
            for (int k = 1; k < 60; ++k) {
                subsize[root_u][k] = subsize[root_v][k - 1];
            }
        }
    }
}

int find_set(int u) {
    if (u != parent[u]) {
        parent[u] = find_set(parent[u]);
    }
    return parent[u];
}

void add_edge(int u, int v) {
    union_set(u, v);
}

int get_kth_largest(int v, int k) {
    int root_v = find_set(v);
    if (k > size[root_v]) return -1;
    return subsize[root_v][k - 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        size[i] = 1;
        subsize[i][0] = i; // Initialize the largest element as the vertex itself
        for (int k = 1; k < 60; ++k) {
            subsize[i][k] = -1;
        }
    }
    int op, u, v, k;
    while (q--) {
        cin >> op >> u >> v;
        if (op == 1) {
            add_edge(u, v);
        } else if (op == 2) {
            cin >> k;
            cout << get_kth_largest(v, k) << '\n';
        }
    }
    return 0;
}