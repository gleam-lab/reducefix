#include "bits/stdc++.h"

using namespace std;

#define ff first
#define ss second
#define ll long long
#define SZ(s) (int)s.size()

const int N = 2e5 + 5;

// Union-Find with DSU and sorted list of nodes in component
struct DSU {
    vector<int> parent;
    vector<set<int>> components;

    DSU(int n) {
        parent.resize(n+1);
        components.resize(n+1);
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
            components[i].insert(i);
        }
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int a, int b) {
        int ra = find(a);
        int rb = find(b);
        if (ra == rb) return;

        // Always merge smaller into larger
        if (components[ra].size() < components[rb].size()) {
            swap(ra, rb);
        }

        // Merge rb's component into ra's
        for (int node : components[rb]) {
            components[ra].insert(node);
        }
        components[rb].clear();
        parent[rb] = ra;
    }

    // Get k-th largest in component containing v
    int query(int v, int k) {
        int rep = find(v);
        if (components[rep].size() < k) return -1;

        auto it = components[rep].rbegin();  // reverse iterator (descending order)
        advance(it, k-1);
        return *it;
    }
};

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    DSU dsu(n);

    while(q--) {
        int t, a, b;
        cin >> t >> a >> b;
        if(t == 1) {
            dsu.unite(a, b);
        } else {
            cout << dsu.query(a, b) << '\n';
        }
    }

    return 0;
}