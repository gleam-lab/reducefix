#include <bits/stdc++.h>
using namespace std;

const int K = 10;

int n, q;
int parent[200005];
set<int> components[200005];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int x, int y) {
    int px = find(x);
    int py = find(y);
    if (px == py) return;

    // Always merge smaller into larger
    if (components[px].size() < components[py].size())
        swap(px, py);

    // Merge the sets
    for (auto it : components[py]) {
        components[px].insert(it);
        if (components[px].size() > K)
            components[px].erase(prev(components[px].end()));
    }

    parent[py] = px;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;

    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        components[i].insert(i);
    }

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int u, v;
            cin >> u >> v;
            unite(u, v);
        } else {
            int v, k;
            cin >> v >> k;
            int pv = find(v);
            if (components[pv].size() < (size_t)k) {
                cout << -1 << '\n';
            } else {
                auto it = next(components[pv].begin(), components[pv].size() - k);
                cout << *it << '\n';
            }
        }
    }

    return 0;
}