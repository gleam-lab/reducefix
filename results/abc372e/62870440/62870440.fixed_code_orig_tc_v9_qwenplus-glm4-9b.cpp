#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_VERTICES = 200005;
const int MAX_ROOTED Vaporizers = 20;
const int MAX_QUERY = 10;

vector<int> parent(MAX_VERTICES);
vector<int> size(MAX_VERTICES);
vector<vector<int>> vertices(MAX_VERTICES);
vector<vector<int>> indexes(MAX_VERTICES);

void initialize(int n) {
    for (int i = 0; i <= n; ++i) {
        parent[i] = i;
        size[i] = 1;
        vertices[i].clear();
    }
}

int find(int v) {
    if (parent[v] != v) {
        parent[v] = find(parent[v]);
    }
    return parent[v];
}

void union_sets(int u, int v) {
    u = find(u);
    v = find(v);
    if (u != v) {
        if (size[u] < size[v]) {
            swap(u, v);
        }
        parent[v] = u;
        size[u] += size[v];
        vertices[u].insert(vertices[u].end(), vertices[v].begin(), vertices[v].end());
        sort(vertices[u].begin(), vertices[u].end());
        indexes[u] = vector<int>(vertices[u].size());
        for (int i = 0; i < (int)vertices[u].size(); ++i) {
            indexes[u][vertices[u][i]] = i;
        }
    }
}

int get_kth_largest(int v, int k) {
    v = find(v);
    if (k > indexes[v].size()) {
        return -1;
    } else {
        return vertices[v][indexes[v][indexes[v].size() - k]];
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    initialize(n);

    while (q--) {
        int type, u, v, k;
        cin >> type;
        if (type == 1) {
            cin >> u >> v;
            union_sets(u, v);
        } else if (type == 2) {
            cin >> v >> k;
            cout << get_kth_largest(v, k) << endl;
        }
    }

    return 0;
}