#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2e5 + 5;

int parent[MAX_N];
set<int> components[MAX_N];

int find(int u) {
    if (parent[u] != u) {
        parent[u] = find(parent[u]);
    }
    return parent[u];
}

void unite(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    if (components[u].size() < components[v].size()) {
        swap(u, v);
    }
    parent[v] = u;
    for (int x : components[v]) {
        components[u].insert(x);
    }
    components[v].clear();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        components[i].insert(i);
    }

    while (Q--) {
        int op, u, v;
        cin >> op >> u >> v;
        if (op == 1) {
            unite(u, v);
        } else {
            int root = find(u);
            if (components[root].size() < v) {
                cout << "-1\n";
            } else {
                auto it = components[root].end();
                advance(it, -v);
                cout << *it << '\n';
            }
        }
    }

    return 0;
}