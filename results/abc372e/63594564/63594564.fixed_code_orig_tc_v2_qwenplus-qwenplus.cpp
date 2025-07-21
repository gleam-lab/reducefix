#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second
#define ll long long
#define SZ(s) ((int)s.size())

const int N = 2e5 + 5;

vector<vector<int>> components(N); // Each component stores up to 10 largest nodes
vector<int> parent(N), rank(N);

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

    // Always attach smaller tree under larger tree
    if (components[rootA].size() < components[rootB].size())
        swap(rootA, rootB);

    // Merge components[rootB] into components[rootA]
    vector<int> merged;
    int i = 0, j = 0;
    while (i < SZ(components[rootA]) && j < SZ(components[rootB])) {
        if (components[rootA][i] > components[rootB][j])
            merged.push_back(components[rootA][i++]);
        else
            merged.push_back(components[rootB][j++]);
    }
    while (i < SZ(components[rootA]))
        merged.push_back(components[rootA][i++]);
    while (j < SZ(components[rootB]))
        merged.push_back(components[rootB][j++]);

    // Keep only top 10 elements
    if (merged.size() > 10)
        merged.resize(10);

    components[rootA] = merged;
    parent[rootB] = rootA;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    // Initialize DSU and components
    for (int i = 0; i <= n; ++i) {
        parent[i] = i;
        rank[i] = 1;
        components[i].push_back(i);
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
            if (SZ(components[root]) < k)
                cout << -1 << '\n';
            else
                cout << components[root][k - 1] << '\n';
        }
    }

    return 0;
}