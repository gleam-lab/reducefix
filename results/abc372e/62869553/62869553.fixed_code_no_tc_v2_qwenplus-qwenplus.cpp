#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int K_LIMIT = 10;

int fa[MAXN];
set<int, greater<int>> components[MAXN];  // Store top 10 nodes in descending order

// Find the root of the set (with path compression)
int find(int x) {
    if (fa[x] != x)
        fa[x] = find(fa[x]);
    return fa[x];
}

// Merge two disjoint sets
void unite(int u, int v) {
    int root_u = find(u);
    int root_v = find(v);
    
    if (root_u == root_v)
        return;

    // Always merge smaller component into larger one for efficiency
    if (components[root_u].size() < components[root_v].size()) {
        swap(root_u, root_v);
        swap(components[root_u], components[root_v]);
    }

    // Merge the contents of root_v into root_u
    for (auto it = components[root_v].begin(); 
         it != components[root_v].end() && components[root_u].size() < K_LIMIT; 
         ++it) {
        components[root_u].insert(*it);
    }
    
    // Update parent
    fa[root_v] = root_u;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N, Q;
    cin >> N >> Q;

    // Initialize DSU and components
    for (int i = 1; i <= N; ++i) {
        fa[i] = i;
        components[i].insert(i);
    }

    while (Q--) {
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
            
            if (k > (int)components[root].size()) {
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