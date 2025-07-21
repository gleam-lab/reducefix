#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int parent[MAXN];
multiset<int, greater<int>> component[MAXN];

// Find with path compression
int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

// Union by size
void unite(int u, int v) {
    int root_u = find(u);
    int root_v = find(v);

    if (root_u == root_v)
        return;

    // Always merge smaller into larger
    if (component[root_u].size() < component[root_v].size()) {
        swap(root_u, root_v);
        swap(component[root_u], component[root_v]);
    }

    // Merge the smaller set into the larger one
    component[root_u].insert(component[root_v].begin(), component[root_v].end());
    parent[root_v] = root_u;
    component[root_v].clear(); // Clear the merged set
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    // Initialize DSU and each component
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        component[i].insert(i);
    }

    while (Q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int u, v;
            cin >> u >> v;
            unite(u, v);
        } else {
            int v, k;
            cin >> v >> k;

            int root = find(v);
            auto& comp = component[root];

            if (comp.size() < (size_t)k) {
                cout << -1 << '\n';
            } else {
                auto it = comp.begin();
                advance(it, k - 1);
                cout << *it << '\n';
            }
        }
    }

    return 0;
}