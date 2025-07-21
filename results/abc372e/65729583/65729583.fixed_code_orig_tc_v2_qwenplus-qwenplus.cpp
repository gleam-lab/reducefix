#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 2 * 100000 + 5;

int parent[MAXN];
multiset<int, greater<int>> components[MAXN];

int find(int u) {
    if (parent[u] != u) {
        parent[u] = find(parent[u]);
    }
    return parent[u];
}

void unite(int u, int v) {
    int pu = find(u);
    int pv = find(v);
    if (pu == pv) return;
    
    // Always merge smaller set into larger one for efficiency
    if (components[pu].size() < components[pv].size()) {
        swap(pu, pv);
    }

    for (int x : components[pv]) {
        components[pu].insert(x);
    }
    components[pv].clear();

    parent[pv] = pu;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    // Initialize DSU
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
        } else {
            int v, k;
            cin >> v >> k;
            int root = find(v);
            auto &comp = components[root];
            if ((int)comp.size() < k) {
                cout << -1 << "\n";
            } else {
                auto it = comp.begin();
                advance(it, k - 1);
                cout << *it << "\n";
            }
        }
    }

    return 0;
}