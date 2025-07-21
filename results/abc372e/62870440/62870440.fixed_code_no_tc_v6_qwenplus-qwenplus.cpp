#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int KMAX = 10;

int fa[MAXN];
set<int, greater<int>> root_sets[MAXN];  // Store top 10 nodes in each DSU root
int node_to_root[MAXN];  // Maps node to its DSU root

// Find the root with path compression
int find(int x) {
    if (fa[x] != x)
        fa[x] = find(fa[x]);
    return fa[x];
}

// Merge two sets: merge small into large
void unite(int u, int v) {
    int ru = find(u);
    int rv = find(v);
    if (ru == rv)
        return;

    // Ensure ru is the larger set
    if (root_sets[ru].size() < root_sets[rv].size())
        swap(ru, rv);

    // Merge elements of rv into ru
    for (int x : root_sets[rv]) {
        root_sets[ru].insert(x);
    }

    // Keep only top KMAX elements
    while (root_sets[ru].size() > KMAX) {
        auto it = prev(root_sets[ru].end());
        root_sets[ru].erase(it);
    }

    // Update parent
    fa[rv] = ru;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, Q;
    cin >> N >> Q;

    // Initialize DSU
    for (int i = 1; i <= N; ++i) {
        fa[i] = i;
        node_to_root[i] = i;
        root_sets[i].insert(i);
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
            
            if (root_sets[root].size() < k) {
                cout << -1 << '\n';
            } else {
                auto it = root_sets[root].begin();
                advance(it, k - 1);
                cout << *it << '\n';
            }
        }
    }

    return 0;
}