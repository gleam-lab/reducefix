#include "bits/stdc++.h"

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
        
    // Merge smaller into larger for better performance
    if (components[rootA].size() < components[rootB].size()) 
        swap(rootA, rootB);
        
    for (int node : components[rootB]) {
        components[rootA].insert(node);
    }
    parent[rootB] = rootA;
}

signed main() {
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
        int t, a, b;
        cin >> t >> a >> b;
        
        if (t == 1) {
            unite(a, b);
        } else {
            int root = find(a);
            if (components[root].size() < b) {
                cout << -1 << '\n';
            } else {
                auto it = components[root].end();
                advance(it, -b);
                cout << *it << '\n';
            }
        }
    }

    return 0;
}