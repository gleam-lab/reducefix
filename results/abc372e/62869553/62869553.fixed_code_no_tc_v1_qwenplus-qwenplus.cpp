#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int K_MAX = 10;

int parent[MAXN];
set<int, greater<int>> group_set[MAXN];  // Stores vertices in descending order for each root

// Find with path compression
int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

// Merge smaller set into larger one for efficiency
void unite(int u, int v) {
    int root_u = find(u);
    int root_v = find(v);
    if (root_u == root_v)
        return;

    // Always merge smaller group into larger group
    if (group_set[root_u].size() < group_set[root_v].size())
        swap(root_u, root_v);

    // Merge the two sets
    for (int node : group_set[root_v])
        group_set[root_u].insert(node);

    // Update parent pointer
    parent[root_v] = root_u;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    // Initialize DSU and sets
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        group_set[i].insert(i);
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
            if (k > (int)group_set[root].size()) {
                cout << -1 << endl;
            } else {
                auto it = group_set[root].begin();
                advance(it, k - 1);
                cout << *it << endl;
            }
        }
    }

    return 0;
}