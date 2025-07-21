#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int TOP_K = 10;

int fa[MAXN];
set<int> components[MAXN]; // Store top 10 largest nodes in each root's component
bool is_root[MAXN];

int find(int x) {
    if (fa[x] != x)
        fa[x] = find(fa[x]);
    return fa[x];
}

void merge(int u, int v) {
    int ru = find(u);
    int rv = find(v);
    if (ru == rv)
        return;

    // Always merge smaller set into larger one to maintain efficiency
    if (components[ru].size() < components[rv].size()) 
        swap(ru, rv);

    for (auto it : components[rv]) {
        components[ru].insert(it);
        if (components[ru].size() > TOP_K)
            components[ru].erase(prev(components[ru].end()));
    }

    fa[rv] = ru;
    is_root[rv] = false;
}

void init_component(int x) {
    components[x].clear();
    components[x].insert(x);
}

int get_kth_largest(int x, int k) {
    int root = find(x);
    if (components[root].size() < k)
        return -1;

    auto it = components[root].rbegin();
    advance(it, k - 1);
    return *it;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, Q;
    cin >> N >> Q;

    for (int i = 1; i <= N; ++i) {
        fa[i] = i;
        is_root[i] = true;
        init_component(i);
    }

    while (Q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int u, v;
            cin >> u >> v;
            merge(u, v);
        } else {
            int v, k;
            cin >> v >> k;
            cout << get_kth_largest(v, k) << '\n';
        }
    }

    return 0;
}