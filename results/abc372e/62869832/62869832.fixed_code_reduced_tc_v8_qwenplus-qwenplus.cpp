#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int K_MAX = 10;

int N, Q;
int parent[MAXN];
set<int> components[MAXN];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int u, int v) {
    int root_u = find(u);
    int root_v = find(v);
    if (root_u == root_v)
        return;

    // Merge smaller set into larger one to keep tree depth small
    if (components[root_u].size() < components[root_v].size()) {
        swap(root_u, root_v);
        swap(components[root_u], components[root_v]);
    }

    for (int node : components[root_v]) {
        components[root_u].insert(node);
    }
    parent[root_v] = root_u;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> Q;

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
            int root_v = find(v);
            auto& comp = components[root_v];
            if (comp.size() < k) {
                cout << -1 << '\n';
            } else {
                auto it = comp.rbegin();
                advance(it, k - 1);
                cout << *it << '\n';
            }
        }
    }

    return 0;
}