#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int const N = 200000 + 5;

vector<int> parent;
vector<set<int>> edges;

int find(int v) {
    if (parent[v] == v) return v;
    parent[v] = find(parent[v]);
    return parent[v];
}

void unionSets(int u, int v) {
    u = find(u);
    v = find(v);
    if (u != v) {
        // Union by smaller set size
        if (edges[v].size() < edges[u].size()) {
            swap(v, u);
        }
        for (int elem : edges[v]) {
            parent[elem] = u;
            edges[u].insert(elem);
        }
        edges[v].clear();
    }
}

int kThLargest(int v, int k) {
    v = find(v);
    if (k > edges[v].size()) return -1;
    set<int>::reverse_iterator rit = edges[v].rbegin();
    advance(rit, k - 1);
    return *rit;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    parent.resize(n + 1);
    edges.resize(n + 1);

    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
    }

    while (q--) {
        int t, u, v, k;
        cin >> t >> u >> v;
        if (t == 1) {
            unionSets(u, v);
        } else {
            cin >> k;
            cout << kThLargest(v, k) << '\n';
        }
    }

    return 0;
}