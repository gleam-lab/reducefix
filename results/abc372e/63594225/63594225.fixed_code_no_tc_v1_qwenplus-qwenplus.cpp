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

    // Merge the smaller component into the larger one
    for (int node : components[rootB]) {
        components[rootA].insert(node);
        parent[node] = rootA;
    }
    
    // Clear the old component to save memory (optional)
    components[rootB].clear();
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    parent.resize(n + 1);
    components.resize(n + 1);

    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        components[i].insert(i);
    }

    while (q--) {
        int type, u, v;
        cin >> type >> u >> v;

        if (type == 1) {
            unite(u, v);
        } else {
            int root = find(u);
            auto& comp = components[root];

            if (v > comp.size()) {
                cout << -1 << '\n';
            } else {
                // Get k-th largest using reverse iterator
                auto it = comp.rbegin();
                advance(it, v - 1);
                cout << *it << '\n';
            }
        }
    }

    return 0;
}