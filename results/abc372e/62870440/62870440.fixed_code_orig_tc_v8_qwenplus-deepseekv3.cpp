#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int parent[MAXN];
int size[MAXN];
multiset<int> components[MAXN];

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int u, int v) {
    u = find_set(u);
    v = find_set(v);
    if (u != v) {
        if (size[u] < size[v])
            swap(u, v);
        parent[v] = u;
        size[u] += size[v];
        components[u].insert(components[v].begin(), components[v].end());
        components[v].clear();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        size[i] = 1;
        components[i].insert(i);
    }

    while (Q--) {
        int op, u, v;
        cin >> op >> u >> v;
        if (op == 1) {
            union_sets(u, v);
        } else {
            int root = find_set(u);
            if (components[root].size() < v) {
                cout << "-1\n";
            } else {
                auto it = components[root].end();
                advance(it, -v);
                cout << *it << "\n";
            }
        }
    }

    return 0;
}