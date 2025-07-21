#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 200005;
const int MAX_K = 10;

int parent[MAX_N]; // Union-Find parent array
int size[MAX_N];   // Union-Find size array
int vertexList[MAX_N][MAX_K]; // Array to store k largest vertices in each connected component
int vertexCount[MAX_N]; // Count of vertices in each connected component

// Find function with path compression
int find(int vertex) {
    return parent[vertex] == vertex ? vertex : parent[vertex] = find(parent[vertex]);
}

// Union function with size optimization
bool unite(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return false;

    if (size[u] < size[v]) swap(u, v);

    // Add smaller component to larger one
    parent[v] = u;
    size[u] += size[v];

    // Merge vertex lists
    for (int i = 0; i < vertexCount[v]; ++i) {
        int vert = vertexList[v][i];
        int pos = upper_bound(vertexList[u], vertexList[u] + vertexCount[u], vert) - vertexList[u];
        if (pos == vertexCount[u]) {
            vertexList[u][pos] = vert;
            vertexCount[u]++;
        } else {
            // Shift elements to make room for the new vertex
            for (int j = vertexCount[u]; j > pos; --j) {
                vertexList[u][j] = vertexList[u][j - 1];
            }
            vertexList[u][pos] = vert;
            vertexCount[u]++;
        }
    }

    return true;
}

int main() {
    int n, q;
    cin >> n >> q;

    // Initialize Union-Find structure
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
        size[i] = 1;
    }

    int op, u, v, k;
    vector<int> results;

    for (int i = 0; i < q; ++i) {
        cin >> op >> u >> v;

        if (op == 1) {
            // Connect vertices u and v
            unite(u - 1, v - 1);
        } else {
            // Process query for k-th largest vertex
            int root = find(u - 1);
            if (vertexCount[root] < k) {
                results.push_back(-1);
            } else {
                results.push_back(vertexList[root][vertexCount[root] - k]); // vertexCount[root] - k == k - 1 + 1 = k
            }
        }
    }

    // Output all results for type 2 queries
    for (int result : results) {
        cout << result << endl;
    }

    return 0;
}