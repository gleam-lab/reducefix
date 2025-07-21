#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 200005;
int parent[MAX_N + 1];
int size[MAX_N + 1];
vector<int> vertices[MAX_N + 1];
vector<int> componentVertices[MAX_N + 1];

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void unionSets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX != rootY) {
        if (size[rootX] < size[rootY]) {
            rootX = rootY;
        }
        parent[rootY] = rootX;
        size[rootX] += size[rootY];
        
        // Merge the vertices
        for (int v : vertices[rootY]) {
            vertices[rootX].push_back(v);
        }
        vertices[rootY].clear();
    }
}

int main() {
    int n, q;
    cin >> n >> q;

    // Initialize parent and size arrays for Union-Find
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        size[i] = 1;
        vertices[i].push_back(i);  // Add vertex to its own list
    }

    while (q--) {
        int op, u, v, k;
        cin >> op >> u >> v;

        if (op == 1) {
            // Union operation
            unionSets(u, v);
        } else {
            // Find the root of v
            int rootV = find(v);
            // Sort the vertices in descending order
            sort(vertices[rootV].begin(), vertices[rootV].end(), greater<int>());
            // Check if k is within the range
            if (k <= vertices[rootV].size()) {
                cout << vertices[rootV][k - 1] << endl;
            } else {
                cout << -1 << endl;
            }
        }
    }

    return 0;
}