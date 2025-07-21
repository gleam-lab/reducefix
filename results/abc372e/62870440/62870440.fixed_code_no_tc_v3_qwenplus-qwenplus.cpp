#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int K_MAX = 10;

int parent[MAXN];
set<int, greater<int>> component[MAXN]; // Store top K_MAX elements in descending order

// Disjoint Set Union (DSU) find with path compression
int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

// Merge smaller component into larger one to maintain efficiency
void unite(int u, int v) {
    int root_u = find(u);
    int root_v = find(v);
    
    if (root_u == root_v)
        return;

    // Always merge smaller set into larger set
    if (component[root_u].size() < component[root_v].size()) {
        swap(root_u, root_v);
        swap(u, v);
    }

    // Merge the smaller component into the larger one
    for (int node : component[root_v]) {
        component[root_u].insert(node);
        if (component[root_u].size() > K_MAX) {
            component[root_u].erase(--component[root_u].end());
        }
    }

    // Update DSU parent
    parent[root_v] = root_u;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N, Q;
    cin >> N >> Q;

    // Initialize DSU and component sets
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
        } else if (type == 2) {
            int v, k;
            cin >> v >> k;

            int root = find(v);

            if (k > component[root].size()) {
                cout << -1 << '\n';
            } else {
                auto it = component[root].begin();
                advance(it, k - 1);
                cout << *it << '\n';
            }
        }
    }

    return 0;
}