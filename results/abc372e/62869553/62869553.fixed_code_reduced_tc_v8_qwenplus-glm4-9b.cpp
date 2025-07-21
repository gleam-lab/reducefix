#include <bits/stdc++.h>
using namespace std;

vector<int> parent;
vector<int> size;
vector<vector<int>> vertices;

int find_set(int x) {
    if (parent[x] != x) {
        parent[x] = find_set(parent[x]);
    }
    return parent[x];
}

void union_sets(int u, int v) {
    int root_u = find_set(u);
    int root_v = find_set(v);

    if (root_u != root_v) {
        if (size[root_u] < size[root_v]) {
            parent[root_u] = root_v;
            size[root_v] += size[root_u];
        } else {
            parent[root_v] = root_u;
            size[root_u] += size[root_v];
        }

        // Merge the vertices of the two sets
        merge(vertices[root_u], vertices[root_v]);
        vertices[root_u] = move(vertices[root_u]); // Take ownership of the merged vector
        vertices[root_v].clear(); // Clear the vector of the other set
    }
}

void merge(vector<int>& a, const vector<int>& b) {
    a.resize(a.size() + b.size());
    copy(b.begin(), b.end(), a.begin() + a.size() - b.size());
    sort(a.begin(), a.end(), greater<int>()); // Sort in descending order
}

int main() {
    int n, q;
    cin >> n >> q;

    parent.resize(n + 1);
    size.resize(n + 1, 1);
    vertices.resize(n + 1);

    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
    }

    for (int i = 0; i < q; ++i) {
        int op, u, v, k;
        cin >> op >> u >> v;
        if (op == 1) {
            union_sets(u, v);
        } else {
            int root_v = find_set(v);
            if (size[root_v] < k) {
                cout << -1 << endl;
            } else {
                cout << vertices[root_v][k - 1] << endl;
            }
        }
    }

    return 0;
}