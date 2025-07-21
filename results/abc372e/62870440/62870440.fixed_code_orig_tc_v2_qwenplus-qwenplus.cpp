#include <bits/stdc++.h>
using namespace std;

const int K_MAX = 10;

int n, q;
vector<int> parent;
vector<set<int, greater<int>>> components; // stores top K_MAX values

// Find function with path compression
int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

// Merge two components
void unite(int u, int v) {
    int root_u = find(u);
    int root_v = find(v);
    if (root_u == root_v) return;

    // Always merge smaller into larger for efficiency
    if (components[root_u].size() < components[root_v].size()) {
        swap(root_u, root_v);
    }

    // Merge elements from root_v into root_u
    for (int val : components[root_v]) {
        components[root_u].insert(val);
        if (components[root_u].size() > K_MAX) {
            auto last = components[root_u].end();
            --last;
            components[root_u].erase(last);
        }
    }

    parent[root_v] = root_u;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;

    parent.resize(n + 1);
    components.resize(n + 1);

    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        components[i].insert(i);
    }

    while (q--) {
        int op;
        cin >> op;

        if (op == 1) {
            int u, v;
            cin >> u >> v;
            unite(u, v);
        } else {
            int v, k;
            cin >> v >> k;
            int root = find(v);
            auto& comp = components[root];
            if (comp.size() < k) {
                cout << "-1\n";
            } else {
                auto it = comp.begin();
                advance(it, k - 1);
                cout << *it << "\n";
            }
        }
    }

    return 0;
}