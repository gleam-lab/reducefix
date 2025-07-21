#include<bits/stdc++.h>
using namespace std;
int parent[200005]; // For union-find
int size[200005]; // For union-find

// Find with path compression
int find(int vertex) {
    if (vertex == parent[vertex]) return vertex;
    parent[vertex] = find(parent[vertex]);
    return parent[vertex];
}

// Union with union by rank
void union_vertices(int u, int v) {
    u = find(u);
    v = find(v);
    if (u != v) {
        if (size[u] < size[v]) {
            parent[u] = v;
            size[v] += size[u];
        } else {
            parent[v] = u;
            size[u] += size[v];
        }
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        size[i] = 1;
    }
    
    while (q--) {
        int op, u, v;
        cin >> op >> u >> v;
        if (op == 1) { // Add edge
            union_vertices(u, v);
        } else if (op == 2) { // Find k-th largest
            int root = find(v);
            vector<int> vertices;
            for (int i = 1; i <= n; i++) {
                if (find(i) == root) {
                    vertices.push_back(i);
                }
            }
            sort(vertices.begin(), vertices.end(), greater<int>());
            if (k <= vertices.size()) {
                cout << vertices[k-1] << "\n";
            } else {
                cout << "-1\n";
            }
        }
    }
    return 0;
}