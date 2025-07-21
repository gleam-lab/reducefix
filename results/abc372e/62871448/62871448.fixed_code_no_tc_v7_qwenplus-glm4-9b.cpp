#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int MAX_L = 12; // Maximum level of tree for path compression

int parent[MAXN];
int size[MAXN];
int max_value[MAX_L][MAXN]; // To store the max value at each level for each component

// Find with path compression and update the max_value
int find(int vertex) {
    if (parent[vertex] != vertex) {
        int root = find(parent[vertex]);
        max_value[log2(size[root])][root] = max(max_value[log2(size[root])][root], max_value[log2(size[vertex])][vertex]);
        parent[vertex] = root;
    }
    return parent[vertex];
}

// Union by size with max_value update
void unite(int u, int v) {
    int root_u = find(u);
    int root_v = find(v);

    if (root_u != root_v) {
        parent[root_u] = root_v;
        size[root_v] += size[root_u];

        // Update the max_value
        max_value[log2(size[root_v])][root_v] = max(max_value[log2(size[root_v])][root_v], max_value[log2(size[root_u])][root_u]);
        max_value[log2(size(root_v))][root_v] = -1; // Indicate that this cell is available for a new max
    }
}

// Get the k-th largest element in the component containing v
int kth_largest(int v, int k) {
    int root_v = find(v);
    for (int i = log2(size[root_v]) - 1; i >= 0; --i) {
        if (max_value[i][root_v] != -1) {
            k--;
            if (k == 0) {
                return max_value[i][root_v];
            }
        }
    }
    return -1;
}

int main() {
    int n, q;
    cin >> n >> q;

    // Initialize parent to itself, size to 1 and max_value to -1 (indicating not set)
    for (int i = 0; i < MAXN; ++i) {
        parent[i] = i;
        size[i] = 1;
        for (int j = 0; j < MAX_L; ++j) {
            max_value[j][i] = -1;
        }
    }

    while (q--) {
        int op, u, v, k;
        cin >> op >> u >> v;

        if (op == 1) { // Union operation
            unite(u, v);
        } else if (op == 2) { // Query operation
            cout << kth_largest(v, k) << "\n";
        }
    }

    return 0;
}