#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

const int N = 2e5 + 9;

vector<int> parent(N), size(N), connected_vertices(N);

void find_set(int u) {
    if (parent[u] == u) return;
    find_set(parent[u]);
    if (size[u] < size[parent[u]]) swap(u, parent[u]);
    parent[u] = parent[parent[u]];
}

void union_sets(int u, int v) {
    find_set(u);
    find_set(v);
    if (u == v) return;
    if (size[u] > size[v]) {
        parent[v] = u;
        size[u] += size[v];
        connected_vertices[u].insert(end(connected_vertices[u]), begin(connected_vertices[v]), end(connected_vertices[v]));
    } else {
        parent[u] = v;
        size[v] += size[u];
        connected_vertices[v].insert(end(connected_vertices[v]), begin(connected_vertices[u]), end(connected_vertices[u]));
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < N; ++i) parent[i] = i;
    while (q--) {
        int type, u, v, k;
        cin >> type;
        if (type == 1) {
            cin >> u >> v;
            union_sets(u, v);
        } else {
            cin >> v >> k;
            find_set(v);
            if (k > connected_vertices[v].size()) cout << -1 << endl;
            else cout << *next(connected_vertices[v].lower_bound(-n), k - 1) << endl;
        }
    }
    return 0;
}