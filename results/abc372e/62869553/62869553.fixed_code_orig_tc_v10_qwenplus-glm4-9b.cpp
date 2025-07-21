#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
int parent[MAXN], size[MAXN];
int kthLargest[MAXN]; // Array to store k-th largest vertices

// Function to find the root of a vertex with path compression
int findRoot(int u) {
    if (parent[u] != u) parent[u] = findRoot(parent[u]);
    return parent[u];
}

// Function to union two sets
void unionSets(int u, int v) {
    int rootU = findRoot(u);
    int rootV = findRoot(v);

    if (rootU != rootV) {
        if (size[rootU] < size[rootV]) swap(rootU, rootV);

        parent[rootV] = rootU;
        size[rootU] += size[rootV];

        // Update k-th largest vertices
        if (size[rootV] < 10) {
            for (int i = 0; i < 10; i++) {
                if (kthLargest[rootV][i] != -1) {
                    if (size[rootU] < 10 + i) {
                        kthLargest[rootU][i + 10] = kthLargest[rootV][i];
                        size[rootU] = 10 + i;
                    }
                    break;
                }
            }
        }
    }
}

int main() {
    int n, q;
    cin >> n >> q;

    // Initialize union-find structure
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        size[i] = 1;
        for (int j = 0; j < 10; j++) kthLargest[i][j] = -1;
        kthLargest[i][0] = i;
    }

    int op, u, v, k;
    while (q--) {
        cin >> op;
        if (op == 1) {
            cin >> u >> v;
            unionSets(u, v);
        } else {
            cin >> v >> k;
            int rootV = findRoot(v);
            if (size[rootV] < k) cout << -1 << endl;
            else cout << kthLargest[rootV][k - 1] << endl;
        }
    }

    return 0;
}