#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int parent[MAXN];
map<int, vector<int>> components;
set<int> visited;

// DSU find with path compression
int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

// Merge two sets using small-to-large technique
void unite(int u, int v) {
    int root_u = find(u);
    int root_v = find(v);

    if (root_u == root_v) return;

    // Always merge smaller into larger
    if (components[root_u].size() < components[root_v].size()) {
        swap(root_u, root_v);
    }

    // Move elements from root_v to root_u
    for (int x : components[root_v]) {
        components[root_u].push_back(x);
    }
    sort(components[root_u].rbegin(), components[root_u].rend());
    components.erase(root_v);
    parent[root_v] = root_u;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;

    // Initialize DSU and components
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        components[i] = {i};
    }

    while (Q--) {
        int op;
        cin >> op;

        if (op == 1) {
            int u, v;
            cin >> u >> v;
            unite(u, v);
        } else if (op == 2) {
            int v, k;
            cin >> v >> k;
            int root = find(v);
            auto& comp = components[root];

            if (k > comp.size()) {
                cout << -1 << '\n';
            } else {
                cout << comp[k - 1] << '\n';
            }
        }
    }

    return 0;
}