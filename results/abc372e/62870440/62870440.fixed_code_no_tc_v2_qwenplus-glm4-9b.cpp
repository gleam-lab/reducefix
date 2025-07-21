#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int MAXLG = 20;
int parent[MAXN], size[MAXN], rank[MAXN], max_vertex[MAXN][MAXLG];
int n, q;

// Find the root of the node x with path compression
int find(int x) {
    if (parent[x] == x) return x;
    parent[x] = find(parent[x]);
    return parent[x];
}

// Perform union of two sets x and y with union by rank
void union_set(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) {
        if (rank[rootX] < rank[rootY]) swap(rootX, rootY);
        if (rank[rootX] == rank[rootY]) rank[rootX]++;
        parent[rootY] = rootX;
        union_max_vertices(rootX, rootY);
    }
}

// Merge the lists of max vertices from both roots
void union_max_vertices(int rootX, int rootY) {
    int verticesX = size[rootX];
    int verticesY = size[rootY];
    int minSize = min(verticesX, verticesY);
    for (int i = verticesX - 1; i >= minSize; --i) {
        max_vertex[rootX][i + minSize] = max_vertex[rootY][i];
    }
    for (int i = minSize - 1; i >= 0; --i) {
        max_vertex[rootX][i] = max_vertex[rootX][i + minSize];
    }
    size[rootX] = verticesX + verticesY;
}

// Initialize the union-find data structure
void init(int n) {
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        size[i] = 1;
        rank[i] = 0;
        for (int j = 0; j < MAXLG; ++j) {
            max_vertex[i][j] = i;
        }
    }
}

// Process the queries
int main() {
    scanf("%d %d", &n, &q);
    init(n);

    for (int i = 0; i < q; ++i) {
        int op, u, v;
        scanf("%d %d %d", &op, &u, &v);
        if (op == 1) { // Add edge
            union_set(u, v);
        } else if (op == 2) { // Query k-th largest vertex
            int rootV = find(v);
            int startTime = size[rootV] - 1, endTime = size[rootV] - 10;
            if (startTime < 0) {
                printf("-1\n");
            } else {
                for (int k = startTime; k >= endTime; --k) {
                    if (max_vertex[rootV][k] != rootV) {
                        printf("%d\n", max_vertex[rootV][k]);
                        break;
                    }
                }
            }
        }
    }
    return 0;
}