#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int parent[MAXN];
set<int, greater<int>> components[MAXN];

int find(int u) {
    if (parent[u] != u)
        parent[u] = find(parent[u]);
    return parent[u];
}

void unite(int u, int v) {
    int rootU = find(u);
    int rootV = find(v);
    if (rootU == rootV) return;

    // Always merge smaller into larger to keep time complexity low
    if (components[rootU].size() < components[rootV].size()) {
        swap(rootU, rootV);
    }

    // Merge the smaller set into the larger set
    for (int val : components[rootV]) {
        components[rootU].insert(val);
    }
    components[rootV].clear();
    parent[rootV] = rootU;
}

int kthLargest(set<int, greater<int>>& s, int k) {
    auto it = s.begin();
    for (int i = 0; i < k - 1 && it != s.end(); ++i) {
        ++it;
    }
    return (it != s.end()) ? *it : -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    // Initialize DSU
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
        } else if (type == 2) {
            int v, k;
            cin >> v >> k;
            int root = find(v);
            cout << kthLargest(components[root], k) << '\n';
        }
    }

    return 0;
}