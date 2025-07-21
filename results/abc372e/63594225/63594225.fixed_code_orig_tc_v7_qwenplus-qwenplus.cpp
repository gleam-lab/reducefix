#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second
#define ll long long
#define SZ(s) (int)s.size()

int const N = 2e5 + 5;

vector<vector<int>> components;
vector<int> parent;

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return;

    // Always merge smaller into larger to reduce overhead
    if (components[a].size() < components[b].size()) swap(a, b);

    // Merge components[b] into components[a]
    vector<int> merged;
    int i = 0, j = 0;
    while (i < components[a].size() && j < components[b].size()) {
        if (components[a][i] > components[b][j]) {
            merged.push_back(components[a][i]);
            ++i;
        } else {
            merged.push_back(components[b][j]);
            ++j;
        }
        if (merged.size() == 100) break;
    }

    while (i < components[a].size() && merged.size() < 100) {
        merged.push_back(components[a][i++]);
    }
    while (j < components[b].size() && merged.size() < 100) {
        merged.push_back(components[b][j++]);
    }

    components[a] = merged;
    parent[b] = a;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    parent.resize(n + 1);
    components.resize(n + 1);

    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
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
            if (components[root].size() < k)
                cout << -1 << '\n';
            else
                cout << components[root][k - 1] << '\n';
        }
    }

    return 0;
}