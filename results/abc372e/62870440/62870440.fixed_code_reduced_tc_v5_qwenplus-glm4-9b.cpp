#include<bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
const int MAXK = 10;

int parent[MAXN];
int size[MAXN];
int as[MAXN][MAXK]; // Array to store edges and associated data

// Initialize union-find structure
void init(int n) {
    for (int i = 0; i <= n; ++i) {
        parent[i] = i;
        size[i] = 1;
        for (int j = 0; j < MAXK; ++j) {
            as[i][j] = 0;
        }
    }
}

// Find operation with path compression
int find(int x) {
    if (x != parent[x]) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

// Union operation with union by rank
void union_set(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) {
        if (size[rootX] < size[rootY]) {
            swap(rootX, rootY);
        }
        parent[rootY] = rootX;
        size[rootX] += size[rootY];
    }
}

// Add edge and associated data
void add_edge(int u, int v, int data) {
    int rootU = find(u);
    int rootV = find(v);
    if (rootU != rootV) {
        union_set(u, v);
        // Add edge and data to u's set
        int k = 0;
        while (as[rootU][k] != 0 && k < MAXK) {
            ++k;
        }
        as[rootU][k] = data;
    }
}

// Find the k-th largest element in the set
int query_kth_largest(int v, int k) {
    int rootV = find(v);
    if (rootV == v) {
        int count = 0;
        for (int i = MAXK - 1; i >= 0; --i) {
            if (as[rootV][i] != 0) {
                ++count;
                if (count >= k) {
                    return as[rootV][i];
                }
            }
        }
    }
    return -1; // Not enough vertices
}

int main() {
    int n, q, u, v, k;
    cin >> n >> q;
    init(n);
    while (q--) {
        cin >> u >> v >> k;
        if (u == 1 && v == 1) {
            cin >> k;
        } else if (u == 1 && v == 2) {
            cout << query_kth_largest(k, v) << endl;
        } else if (u == 2 && v == 1) {
            add_edge(k, v, u);
        } else if (u == 2 && v == 2) {
            cout << query_kth_largest(k, v) << endl;
        }
    }
    return 0;
}