#include<bits/stdc++.h>
using namespace std;
const int MAXN = 200005, LOGN = 18;

int parent[MAXN], size[MAXN], rank[MAXN], maxVertex[MAXN];
int n, q;

void initialize() {
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        size[i] = 1;
        rank[i] = 0;
        maxVertex[i] = -1; // Initialize to -1 indicating not yet set
    }
}

int find(int u) {
    if (u != parent[u]) {
        int root = find(parent[u]);
        parent[u] = root;
    }
    return parent[u];
}

void unite(int u, int v) {
    int rootU = find(u);
    int rootV = find(v);
    
    if (rootU != rootV) {
        // Union by rank
        if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
            size[rootV] += size[rootU];
        } else if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
            size[rootU] += size[rootV];
        } else {
            parent[rootV] = rootU;
            rank[rootU] += 1;
            size[rootU] += size[rootV];
        }
        
        // Update maxVertex
        if (maxVertex[rootU] > maxVertex[rootV]) {
            maxVertex[rootU] = maxVertex[rootV];
        } else if (maxVertex[rootU] < maxVertex[rootV]) {
            maxVertex[rootU] = maxVertex[rootV];
        }
    }
}

int kthLargest(int v, int k) {
    int root = find(v);
    
    // Find the k-th largest element
    for (int i = LOGN - 1; i >= 0; --i) {
        int maxV = maxVertex[root];
        if (maxV >= 0) {
            k--;
            if (k == 0) return maxV;
            root = parent[root];
        }
    }
    return -1; // If k is larger than the number of vertices in the component
}

int main() {
    cin >> n >> q;
    initialize();
    
    while (q--) {
        int op, u, v, k;
        cin >> op >> u >> v;
        
        if (op == 1) {
            unite(u, v);
        } else if (op == 2) {
            cout << kthLargest(v, k) << endl;
        }
    }
    
    return 0;
}