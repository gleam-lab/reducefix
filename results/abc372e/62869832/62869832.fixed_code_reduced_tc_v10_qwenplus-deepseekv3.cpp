#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
int parent[MAXN];
set<int, greater<int>> components[MAXN];

int find(int u) {
    if (parent[u] != u) {
        parent[u] = find(parent[u]);
    }
    return parent[u];
}

void unite(int u, int v) {
    int root_u = find(u);
    int root_v = find(v);
    if (root_u == root_v) return;
    
    if (components[root_u].size() < components[root_v].size()) {
        swap(root_u, root_v);
    }
    
    for (int x : components[root_v]) {
        components[root_u].insert(x);
        if (components[root_u].size() > 10) {
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
                auto it = components[root].begin();
                advance(it, v - 1);
                cout << *it << '\n';
            }
        }
    }
    
    return 0;
}