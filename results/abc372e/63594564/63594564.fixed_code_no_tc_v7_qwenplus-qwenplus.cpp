#include <bits/stdc++.h>

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

    // Merge smaller set into larger one to optimize performance
    if (components[rootA].size() < components[rootB].size())
        swap(rootA, rootB);

    // Move all elements from smaller component to larger one
    components[rootA].insert(components[rootB].begin(), components[rootB].end());

    parent[rootB] = rootA;
    // Free memory of the merged component
    components[rootB].clear();
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    components.resize(n + 1);
    parent.resize(n + 1);

    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        components[i].insert(i);
    }

    while (q--) {
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 1) {
            unite(u, v);
        } else {
            int root = find(u);
            if (components[root].size() < v) {
                cout << -1 << '\n';
            } else {
                // Get k-th largest using reverse iterator
                auto it = components[root].rbegin();
                for (int i = 1; i < v && it != components[root].rend(); ++i)
                    ++it;
                cout << *it << '\n';
            }
        }
    }

    return 0;
}