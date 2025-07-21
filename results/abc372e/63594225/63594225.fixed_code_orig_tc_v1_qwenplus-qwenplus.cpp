#include "bits/stdc++.h"

using namespace std;

#define ff first
#define ss second
#define ll long long
#define SZ(s) ((int)(s).size())

const int N = 2e5 + 5;

vector<vector<int>> components(N); // Stores top 10 largest nodes in each component
vector<int> parent(N);

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int u, int v) {
    int root_u = find(u);
    int root_v = find(v);
    
    if (root_u == root_v)
        return;

    // Always merge smaller into larger to optimize DSU
    if (components[root_u].size() < components[root_v].size())
        swap(root_u, root_v);

    // Merge the data
    vector<int> merged;
    auto &a = components[root_u];
    auto &b = components[root_v];

    int i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] > b[j]) {
            merged.push_back(a[i++]);
        } else {
            merged.push_back(b[j++]);
        }
        if (merged.size() == 10)
            break;
    }

    // Finish filling if not full yet
    while (i < a.size() && merged.size() < 10)
        merged.push_back(a[i++]);
    while (j < b.size() && merged.size() < 10)
        merged.push_back(b[j++]);

    components[root_u] = merged;
    parent[root_v] = root_u;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    // Initialize DSU and components
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        components[i].push_back(i);
    }

    while (q--) {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 1) {
            unite(a, b);
        } else {
            int root = find(a);
            if (components[root].size() < b)
                cout << -1 << '\n';
            else
                cout << components[root][b - 1] << '\n';
        }
    }

    return 0;
}