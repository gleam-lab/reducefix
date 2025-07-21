#include "bits/stdc++.h"

using namespace std;

#define ff first
#define ss second
#define ll long long
#define SZ(s) (int)s.size()

int const N = 2e5 + 5;

vector <set<int>> components;
vector <int> parent;

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);
    
    if (rootA == rootB)
        return;

    // Always merge smaller set into larger one
    if (components[rootA].size() < components[rootB].size())
        swap(rootA, rootB);

    // Merge the smaller component into the larger one
    for (int val : components[rootB]) {
        components[rootA].insert(val);
    }
    
    parent[rootB] = rootA;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    components.resize(n + 1);
    parent.resize(n + 1);

    for (int i = 1; i <= n; ++i) {
        components[i].insert(i);
        parent[i] = i;
    }

    while (q--) {
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
            
            if (components[root].size() < (size_t)k) {
                cout << -1 << '\n';
            } else {
                // We need to find the k-th largest element in the set
                auto it = components[root].rbegin();  // reverse iterator
                advance(it, k - 1);
                cout << *it << '\n';
            }
        }
    }

    return 0;
}