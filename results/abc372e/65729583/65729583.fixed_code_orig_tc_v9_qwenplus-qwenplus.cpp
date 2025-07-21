#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 2 * 1e5 + 5;

int parent[MAXN];
set<int> components[MAXN];

int find(int u) {
    if (parent[u] != u)
        parent[u] = find(parent[u]);
    return parent[u];
}

void unite(int u, int v) {
    int root_u = find(u);
    int root_v = find(v);

    if (root_u == root_v)
        return;

    // Always merge smaller set into larger one for efficiency
    if (components[root_u].size() < components[root_v].size()) {
        swap(root_u, root_v);
    }

    // Merge the smaller set into the larger one
    for (int x : components[root_v]) {
        components[root_u].insert(x);
        parent[x] = root_u;
    }
    components[root_v].clear();
}

int kth_largest(int v, int k) {
    int root_v = find(v);
    if ((int)components[root_v].size() < k)
        return -1;
    
    auto it = components[root_v].end();
    for (int i = 0; i < k; ++i)
        --it;
    return *it;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;

    // Initialize DSU
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        components[i].insert(i);
    }

    for (int i = 0; i < Q; ++i) {
        int type;
        cin >> type;

        if (type == 1) {
            int u, v;
            cin >> u >> v;
            unite(u, v);
        } else {
            int v, k;
            cin >> v >> k;
            cout << kth_largest(v, k) << "\n";
        }
    }

    return 0;
}