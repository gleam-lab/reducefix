#include "bits/stdc++.h"

using namespace std;

#define ff first
#define ss second
#define ll long long
#define SZ(s) (int)s.size()

int const N = 2e5 + 5;

vector <set<int, greater<int>>> component(N); // stores top 10 largest nodes in descending order
vector <int> parent(N);

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int a, int b) {
    int root_a = find(a);
    int root_b = find(b);
    if (root_a == root_b)
        return;

    // Always merge smaller into larger for efficiency
    if (component[root_a].size() < component[root_b].size())
        swap(root_a, root_b);

    // Merge the two sets while keeping only top 10 elements
    set<int, greater<int>> &dest = component[root_a];
    set<int, greater<int>> &src = component[root_b];

    for (int val : src)
        dest.insert(val);

    // Keep only the top 10 largest values
    while (dest.size() > 10)
        dest.erase(prev(dest.end()));

    parent[root_b] = root_a;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    // Initialize each node as its own parent and contains itself
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        component[i].insert(i);
    }

    while (q--) {
        int t;
        cin >> t;

        if (t == 1) {
            int u, v;
            cin >> u >> v;
            unite(u, v);
        } else {
            int v, k;
            cin >> v >> k;
            int root = find(v);
            auto &nodes = component[root];
            if (nodes.size() < k)
                cout << -1 << '\n';
            else {
                auto it = nodes.begin();
                advance(it, k - 1);
                cout << *it << '\n';
            }
        }
    }

    return 0;
}