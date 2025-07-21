#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int K_MAX = 10;

int parent[MAXN];
set<int, greater<int>> components[MAXN]; // Store top 10 largest nodes in descending order

// DSU find with path compression
int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

// Merge two components: merge small into large
void unite(int u, int v) {
    int root_u = find(u);
    int root_v = find(v);
    
    if (root_u == root_v)
        return;

    // Always merge smaller set into larger one for efficiency
    if (components[root_u].size() < components[root_v].size()) {
        swap(root_u, root_v);
    }

    // Merge the two sets while maintaining only top K_MAX elements
    for (int node : components[root_v]) {
        components[root_u].insert(node);
        if (components[root_u].size() > K_MAX) {
            components[root_u].erase(prev(components[root_u].end()));
        }
    }

    parent[root_v] = root_u;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    // Initialize DSU and component sets
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        components[i].insert(i);
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
            if (k > components[root].size()) {
                cout << -1 << '\n';
            } else {
                auto it = components[root].begin();
                advance(it, k - 1);
                cout << *it << '\n';
            }
        }
    }

    return 0;
}