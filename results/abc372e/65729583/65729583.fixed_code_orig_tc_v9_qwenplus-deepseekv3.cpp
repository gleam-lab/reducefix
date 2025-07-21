#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<int> parent;
vector<set<int>> component;

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
    if (component[u].size() < component[v].size()) {
        swap(u, v);
    }
    parent[v] = u;
    for (int x : component[v]) {
        component[u].insert(x);
    }
    component[v].clear();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    parent.resize(N + 1);
    component.resize(N + 1);

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
            v = find(v);
            if (component[v].size() < k) {
                cout << -1 << '\n';
            } else {
                auto it = component[v].end();
                advance(it, -k);
                cout << *it << '\n';
            }
        }
    }

    return 0;
}