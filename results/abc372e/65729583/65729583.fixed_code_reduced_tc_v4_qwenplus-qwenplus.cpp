#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

const int MAXN = 2 * 100000 + 5;

int parent[MAXN];
set<int> components[MAXN]; // Each root has its own set of nodes in decreasing order

int find(int u) {
    if (parent[u] != u)
        parent[u] = find(parent[u]);
    return parent[u];
}

void unite(int u, int v) {
    int root_u = find(u);
    int root_v = find(v);

    if (root_u == root_v)
        return;

    // Always merge smaller set into larger set
    if (components[root_u].size() < components[root_v].size()) {
        swap(root_u, root_v);
    }

    // Merge component_v into component_u
    for (int x : components[root_v]) {
        components[root_u].insert(x);
    }
    components[root_v].clear();
    parent[root_v] = root_u;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    // Initialize DSU
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        components[i].insert(-i); // Store negative values for descending order
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
            if ((int)components[root].size() < k) {
                cout << -1 << "\n";
            } else {
                auto it = components[root].begin();
                advance(it, k - 1);
                cout << -(*it) << "\n"; // negate back to get actual value
            }
        }
    }

    return 0;
}