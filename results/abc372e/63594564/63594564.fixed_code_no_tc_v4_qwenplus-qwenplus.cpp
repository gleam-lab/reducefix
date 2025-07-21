#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second
#define ll long long
#define SZ(s) (int)s.size()

const int N = 2e5 + 5;

vector<set<int>> component_sets;
vector<int> parent;

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

    // Always merge smaller set into larger one for efficiency
    if (component_sets[root_a].size() < component_sets[root_b].size()) {
        swap(root_a, root_b);
    }

    // Merge the sets
    for (int node : component_sets[root_b]) {
        component_sets[root_a].insert(node);
    }
    
    // Update parent pointers
    parent[root_b] = root_a;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    parent.resize(n + 1);
    component_sets.resize(n + 1);

    // Initialize each node as its own component
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        component_sets[i].insert(i);
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

            // Use a vector to sort and get k-th largest
            vector<int> temp(component_sets[root].begin(), component_sets[root].end());
            sort(temp.rbegin(), temp.rend());

            if (k <= temp.size())
                cout << temp[k - 1] << '\n';
            else
                cout << -1 << '\n';
        }
    }

    return 0;
}