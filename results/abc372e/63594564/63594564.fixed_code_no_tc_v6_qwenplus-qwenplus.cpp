#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second
#define SZ(s) (int)(s).size()

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

    // Always merge smaller set into the larger one for efficiency
    if (components[rootA].size() < components[rootB].size())
        swap(rootA, rootB);

    // Merge components[rootB] into components[rootA]
    components[rootA].insert(components[rootB].begin(), components[rootB].end());
    parent[rootB] = rootA;
}

int main() {
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
        int t, u, v;
        cin >> t >> u >> v;

        if (t == 1) {
            unite(u, v);
        } else {
            int root = find(u);
            if (SZ(components[root]) < v) {
                cout << -1 << '\n';
            } else {
                auto it = components[root].end();
                advance(it, -v);
                cout << *it << '\n';
            }
        }
    }

    return 0;
}