#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int MAX_EDGES = 10;  // Since there can be at most 10 edges between any two vertices

int parent[MAXN];  // Union-Find parent array
int size[MAXN];    // Size of the union-find set
int maxEdge[MAXN][MAX_EDGES];  // Array to store the maximum edge in each component

// Function to find the root of the vertex x with path compression
int findRoot(int x) {
    if (parent[x] != x) {
        parent[x] = findRoot(parent[x]);
    }
    return parent[x];
}

// Function to union two sets containing the vertices x and y
void unionSets(int x, int y) {
    int rootX = findRoot(x);
    int rootY = findRoot(y);

    if (rootX != rootY) {
        if (size[rootX] >= size[rootY]) {
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
            // Update the maximum edge in the rootX component
            for (int j = 0; j < MAX_EDGES; ++j) {
                if (maxEdge[rootX][j] == -1 || maxEdge[rootY][j] > maxEdge[rootX][j]) {
                    maxEdge[rootX][j] = maxEdge[rootY][j];
                }
            }
        } else {
            parent[rootX] = rootY;
            size[rootY] += size[rootX];
            // Update the maximum edge in the rootY component
            for (int j = 0; j < MAX_EDGES; ++j) {
                if (maxEdge[rootY][j] == -1 || maxEdge[rootX][j] > maxEdge[rootY][j]) {
                    maxEdge[rootY][j] = maxEdge[rootX][j];
                }
            }
        }
    }
}

// Function to solve the problem
int main() {
    int n, q;
    cin >> n >> q;

    // Initialize union-find structure
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        size[i] = 1;
        for (int j = 0; j < MAX_EDGES; ++j) {
            maxEdge[i][j] = -1;
        }
    }

    // Process each query
    while (q--) {
        int op, u, v, k;
        cin >> op >> u >> v;
        if (op == 1) {
            // Add edge u-v
            unionSets(u, v);
        } else if (op == 2) {
            // Find the k-th largest connected vertex to v
            int rootV = findRoot(v);
            if (k > size[rootV]) {
                cout << -1 << endl;
            } else {
                // Output the k-th largest vertex
                cout << maxEdge[rootV][MAX_EDGES - size[rootV] + k - 1] << endl;
            }
        }
    }

    return 0;
}