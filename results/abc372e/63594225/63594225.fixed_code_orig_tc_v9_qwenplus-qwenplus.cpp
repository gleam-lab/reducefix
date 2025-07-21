#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second
#define ll long long
#define SZ(s) ((int)(s).size()

int const N = 2e5 + 5;

vector<vector<int>> components(N);
vector<int> parent(N), sz(N);

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return;

    // Always merge smaller into larger
    if (components[a].size() < components[b].size()) swap(a, b);

    // Merge sorted lists and keep top 100 elements
    vector<int> merged;
    auto &va = components[a], &vb = components[b];

    int i = 0, j = 0;
    while (i < va.size() && j < vb.size()) {
        if (va[i] > vb[j]) {
            merged.push_back(va[i++]);
        } else {
            merged.push_back(vb[j++]);
        }
        if (merged.size() > 100) merged.pop_back();
    }

    while (i < va.size()) {
        merged.push_back(va[i++]);
        if (merged.size() > 100) merged.pop_back();
    }

    while (j < vb.size()) {
        merged.push_back(vb[j++]);
        if (merged.size() > 100) merged.pop_back();
    }

    components[a].swap(merged);
    parent[b] = a;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    // Initialize DSU
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
            if (SZ(components[root]) < k)
                cout << -1 << '\n';
            else
                cout << components[root][k - 1] << '\n';
        }
    }

    return 0;
}