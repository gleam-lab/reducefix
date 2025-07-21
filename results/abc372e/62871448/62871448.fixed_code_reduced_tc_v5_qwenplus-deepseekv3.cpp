#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
int parent[MAXN];
multiset<int, greater<int>> components[MAXN];

int find(int u) {
    if (parent[u] != u) {
        parent[u] = find(parent[u]);
    }
    return parent[u];
}

void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    if (components[u].size() < components[v].size()) {
        swap(u, v);
    }
    for (int x : components[v]) {
        components[u].insert(x);
    }
    components[v].clear();
    parent[v] = u;
    while (components[u].size() > 10) {
        components[u].erase(--components[u].end());
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

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
            merge(u, v);
        } else {
            u = find(u);
            if (components[u].size() < v) {
                cout << "-1\n";
            } else {
                auto it = components[u].begin();
                advance(it, v - 1);
                cout << *it << "\n";
            }
        }
    }

    return 0;
}