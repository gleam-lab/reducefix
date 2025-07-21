#include<bits/stdc++.h>
using namespace std;
vector<int> graph[200005];
int parent[200005];
int size[200005];
int n, q;

// Find the root of the vertex v with path compression
int find(int v) {
    if (parent[v] == v) return v;
    parent[v] = find(parent[v]);
    return parent[v];
}

// Union by size of the sets containing v and u
void unionSets(int u, int v) {
    int root_u = find(u);
    int root_v = find(v);
    if (root_u != root_v) {
        if (size[root_u] < size[root_v]) {
            root_u = root_v;
            root_v = u;
        }
        parent[root_v] = root_u;
        size[root_u] += size[root_v];
    }
}

// Add edge between vertices u and v
void addEdge(int u, int v) {
    unionSets(u, v);
    if (find(u) == find(v)) {
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}

// Process a type 2 query for vertex v and k
void processQuery(int v, int k) {
    int root = find(v);
    vector<int> connected_vertices = graph[root];

    // Sort the connected vertices in descending order
    sort(connected_vertices.rbegin(), connected_vertices.rend());

    // Print the k-th largest vertex if there are at least k vertices connected
    if (k <= connected_vertices.size()) {
        cout << connected_vertices[k - 1] << endl;
    } else {
        cout << "-1" << endl;
    }
}

int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        size[i] = 1;
    }

    for (int i = 0; i < q; i++) {
        int op, u, v, k;
        cin >> op >> u >> v;
        if (op == 1) {
            addEdge(u, v);
        } else if (op == 2) {
            cin >> k;
            processQuery(v, k);
        }
    }

    return 0;
}