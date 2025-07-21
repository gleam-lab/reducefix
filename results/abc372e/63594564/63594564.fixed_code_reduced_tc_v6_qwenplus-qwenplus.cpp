#include "bits/stdc++.h"

using namespace std;

#define ff first
#define ss second
#define ll long long
#define SZ(s) (int)s.size()

int const N = 2e5 + 5;

vector<set<int>> components;
vector<int> parent;

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

    // Move all elements from rootB to rootA
    for (int val : components[rootB]) {
        components[rootA].insert(val);
    }
    
    // Clear and update parent
    components[rootB].clear();
    parent[rootB] = rootA;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    components.resize(n + 1);
    parent.resize(n + 1);

    // Initialize each node as its own component
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
        } 
        else {
            int v, k;
            cin >> v >> k;

            int root = find(v);
            
            if (components[root].size() < (size_t)k) {
                cout << -1 << '\n';
            } else {
                // Get the k-th largest element
                auto it = components[root].end();
                advance(it, -k);
                cout << *it << '\n';
            }
        }
    }

    return 0;
}