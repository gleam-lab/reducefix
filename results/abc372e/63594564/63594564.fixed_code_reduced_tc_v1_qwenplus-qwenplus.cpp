#include "bits/stdc++.h"

using namespace std;

#define ff first
#define ss second
#define ll long long
#define SZ(s) (int)s.size()

int const N = 2e5 + 5;

vector <set<int>> components;
vector <int> parent;

int find(int x) {
    if(parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if(a == b) return;
    
    // Always merge smaller into larger to optimize performance
    if(components[a].size() < components[b].size())
        swap(a, b);
    
    for(int x : components[b]) {
        components[a].insert(x);
        parent[x] = a;
    }
    components[b].clear(); // Optional: free memory
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    components.resize(n + 1);
    parent.resize(n + 1);
    
    for(int i = 1; i <= n; ++i) {
        parent[i] = i;
        components[i].insert(i);
    }

    while(q--) {
        int t, u, v;
        cin >> t >> u >> v;
        if(t == 1) {
            unite(u, v);
        } else {
            int root = find(u);
            if(components[root].size() < (size_t)v) {
                cout << -1 << '\n';
            } else {
                auto it = prev(components[root].end(), v);
                cout << *it << '\n';
            }
        }
    }

    return 0;
}