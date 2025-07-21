#include <bits/stdc++.h>
using namespace std;

// Number of vertices
int N;
// Number of queries
int Q;
// Array to hold the parent of each vertex
int fa[N + 1];
// Array to hold the size of each component
int sz[N + 1];

// Function to find the root of the component containing x using path compression
int gtf(int x, int fa[], int sz[]) {
    if (fa[x] != x) {
        fa[x] = gtf(fa[x], fa, sz); // Path compression
    }
    return fa[x];
}

// Function to merge two components
void merge(int x, int y, int fa[], int sz[]) {
    int rootX = gtf(x, fa, sz);
    int rootY = gtf(y, fa, sz);
    if (rootX != rootY) {
        if (sz[rootX] > sz[rootY]) {
            fa[rootY] = rootX;
            sz[rootX] += sz[rootY];
        } else {
            fa[rootX] = rootY;
            sz[rootY] += sz[rootX];
        }
    }
}

// Function to find the k-th largest vertex in the component containing v
int k_largest(int v, int fa[], int sz[]) {
    int root = gtf(v, fa, sz);
    int n = sz[root];
    if (n < 10) return -1;
    return root + 10 - n; // Return the index of the k-th largest vertex
}

int main() {
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        fa[i] = i;
        sz[i] = 1; // Initially, each vertex forms its own component
    }

    int u, v, op, k;
    while (Q--) {
        cin >> op;
        if (op == 1) {
            cin >> u >> v;
            merge(u, v, fa, sz);
        } else {
            cin >> v >> k;
            cout << k_largest(v, fa, sz) << '\n';
        }
    }

    return 0;
}