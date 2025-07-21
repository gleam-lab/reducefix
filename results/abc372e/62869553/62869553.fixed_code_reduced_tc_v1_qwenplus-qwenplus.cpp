#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int parent[MAXN];
int sz[MAXN];
set<int, greater<>> components[MAXN];

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

    // Merge smaller set into larger
    if (sz[root_u] < sz[root_v]) {
        swap(root_u, root_v);
    }

    for (int val : components[root_v]) {
        components[root_u].insert(val);
    }

    components[root_v].clear();
    parent[root_v] = root_u;
    sz[root_u] += sz[root_v];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        sz[i] = 1;
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
            if ((int)components[root].size() < k) {
                cout << -1 << "\n";
            } else {
                auto it = components[root].begin();
                advance(it, k - 1);
                cout << *it << "\n";
            }
        }
    }

    return 0;
}