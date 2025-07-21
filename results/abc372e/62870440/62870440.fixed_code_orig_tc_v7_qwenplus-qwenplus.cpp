#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
int N, Q;
int parent[MAXN];
multiset<int, greater<int>> component[MAXN];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int u, int v) {
    int root_u = find(u);
    int root_v = find(v);
    if (root_u == root_v) return;

    // Always merge smaller set into the larger one
    if (component[root_u].size() < component[root_v].size())
        swap(root_u, root_v);

    // Merge the sets
    component[root_u].insert(component[root_v].begin(), component[root_v].end());
    parent[root_v] = root_u;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> Q;

    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        component[i].insert(i);
    }

    while (Q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int u, v;
            cin >> u >> v;
            unite(u, v);
        } else {
            int v, k;
            cin >> v >> k;
            int root_v = find(v);
            if (k > (int)component[root_v].size()) {
                cout << -1 << '\n';
            } else {
                auto it = component[root_v].begin();
                advance(it, k - 1);
                cout << *it << '\n';
            }
        }
    }

    return 0;
}