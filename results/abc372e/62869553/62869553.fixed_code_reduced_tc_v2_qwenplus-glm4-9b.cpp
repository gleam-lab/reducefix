#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 200005;

int parent[MAX_N], size[MAX_N], vertices_in_component[MAX_N];

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void union_vertices(int u, int v) {
    int root_u = find(u);
    int root_v = find(v);
    if (root_u != root_v) {
        if (size[root_u] < size[root_v]) {
            swap(root_u, root_v);
        }
        parent[root_v] = root_u;
        size[root_u] += size[root_v];
        if (size[root_u] > vertices_in_component[root_u].size()) {
            // Remove the largest element
            vertices_in_component[root_u].erase(vertices_in_component[root_u].end() - 1);
        }
    }
}

int main() {
    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n; ++i) {
        parent[i] = i;
        size[i] = 1;
        vertices_in_component[i].push_back(i);
    }

    for (int i = 0; i < q; ++i) {
        int op, u, v, k;
        cin >> op >> u >> v;

        if (op == 1) { // Add edge
            union_vertices(u - 1, v - 1);
        } else if (op == 2) { // Find k-th largest
            int root_v = find(v - 1);
            if (k > vertices_in_component[root_v].size()) {
                cout << -1 << '\n';
            } else {
                cout << vertices_in_component[root_v][vertices_in_component[root_v].size() - k] + 1 << '\n';
            }
        }
    }

    return 0;
}