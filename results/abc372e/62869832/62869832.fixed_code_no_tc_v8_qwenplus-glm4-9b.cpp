#include<bits/stdc++.h>
using namespace std;
int parent[200005];
vector<int> adj[200005];
int find_set(int node) {
    if (parent[node] != node) {
        parent[node] = find_set(parent[node]);  // Path compression
    }
    return parent[node];
}

void union_set(int u, int v) {
    int root_u = find_set(u);
    int root_v = find_set(v);
    if (root_u != root_v) {
        parent[root_v] = root_u;  // Union by rank can be implemented if needed
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    while (q--) {
        int op, u, v, k;
        cin >> op >> u >> v;
        if (op == 1) {
            union_set(u, v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        } else if (op == 2) {
            int root_v = find_set(v);
            vector<int> connected_vertices;
            for (auto neighbor : adj[root_v]) {
                connected_vertices.push_back(neighbor);
            }
            if (k > connected_vertices.size()) {
                cout << -1 << endl;
            } else {
                cout << connected_vertices[connected_vertices.size() - k] << endl;
            }
        }
    }
    return 0;
}