#include <bits/stdc++.h>
using namespace std;

const int K_MAX = 10;

int n, q;
vector<int> parent;
vector<set<int, greater<int>>> components;

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int x, int y) {
    int px = find(x);
    int py = find(y);
    if (px == py) return;

    // Merge smaller into larger
    if (components[px].size() < components[py].size()) swap(px, py);

    for (int val : components[py]) {
        components[px].insert(val);
        if (components[px].size() > K_MAX)
            components[px].erase(--components[px].end());
    }

    parent[py] = px;
}

int query(int v, int k) {
    int pv = find(v);
    auto it = components[pv].begin();
    if (k > components[pv].size()) return -1;
    advance(it, k - 1);
    return *it;
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
            cout << query(v, k) << '\n';
        }
    }

    return 0;
}