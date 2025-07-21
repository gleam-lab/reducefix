#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

typedef long long ll;
const int K_LIMIT = 10;

int parent[200005];
set<int> components[200005];

int find(int u) {
    return parent[u] == u ? u : parent[u] = find(parent[u]);
}

void unite(int u, int v) {
    int pu = find(u);
    int pv = find(v);
    if (pu == pv) return;

    // Always merge smaller set into larger set
    if (components[pu].size() < components[pv].size()) swap(pu, pv);

    // Move elements from pv to pu
    for (int x : components[pv]) {
        components[pu].insert(x);
        if (components[pu].size() > K_LIMIT) {
            components[pu].erase(prev(components[pu].end()));
        }
    }

    components[pv].clear();
    parent[pv] = pu;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, Q;
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
        } else {
            int v, k;
            cin >> v >> k;
            int root = find(v);
            if (components[root].size() < k) {
                cout << -1 << '\n';
            } else {
                auto it = prev(components[root].end(), k);
                cout << *it << '\n';
            }
        }
    }

    return 0;
}