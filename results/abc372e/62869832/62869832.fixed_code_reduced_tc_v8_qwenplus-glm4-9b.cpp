#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 200005;

int parent[MAXN];
vector<int> vertices[MAXN]; // To store vertices in each component

// Find the root of the component containing x, with path compression
int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

// Unite the components containing x and y
void unite(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) {
        parent[rootY] = rootX;
        vertices[rootX].insert(vertices[rootX].end(), vertices[rootY].begin(), vertices[rootY].end());
        sort(vertices[rootX].rbegin(), vertices[rootX].rend()); // Keep the vertices sorted
    }
}

int main() {
    int n, q;
    cin >> n >> q;

    // Initialize parent arrays and union-find structure
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        vertices[i].push_back(i);
    }

    while (q--) {
        int op, v, k;
        cin >> op >> v >> k;

        if (op == 1) { // Add edge
            v--;
            int u = v + 1; // Convert to 1-based index
            unite(u, v);
        } else if (op == 2) { // Query k-th largest vertex
            v--;
            int rootV = find(v);
            if (vertices[rootV].size() < k) {
                cout << -1 << endl;
            } else {
                cout << vertices[rootV][k - 1] << endl;
            }
        }
    }

    return 0;
}