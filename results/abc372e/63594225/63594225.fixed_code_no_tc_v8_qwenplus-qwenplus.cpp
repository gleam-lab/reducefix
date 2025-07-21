#include "bits/stdc++.h"

using namespace std;

#define ff first
#define ss second
#define ll long long
#define SZ(s) (int)s.size()

int const N = 2e5 + 5;

vector<set<int>> components;
vector<int> p;

int par(int x) {
    if (p[x] == x) return x;
    return p[x] = par(p[x]);
}

void uni(int a, int b) {
    a = par(a);
    b = par(b);
    if (a == b) return;
    
    // Always merge smaller into larger for efficiency
    if (components[a].size() < components[b].size()) swap(a, b);

    // Merge the sets
    for (int node : components[b]) {
        components[a].insert(node);
        p[node] = a;
    }
    
    // Keep only top 10 values in descending order
    while (components[a].size() > 10) {
        components[a].erase(prev(components[a].end()));
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    p.resize(n+1);
    components.resize(n+1);

    for (int i = 1; i <= n; ++i) {
        p[i] = i;
        components[i].insert(i);
    }

    while (q--) {
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 1) {
            uni(u, v);
        } else {
            int root = par(u);
            if (components[root].size() < (size_t)v) {
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