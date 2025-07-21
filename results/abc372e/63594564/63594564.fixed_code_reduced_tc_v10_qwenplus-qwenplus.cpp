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
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);
    
    if (rootA == rootB)
        return;
        
    // Always merge smaller set into larger one
    if (components[rootA].size() < components[rootB].size())
        swap(rootA, rootB);

    // Merge the smaller component into the larger one
    for (int node : components[rootB]) {
        components[rootA].insert(node);
        parent[node] = rootA;
    }
    // Clear the smaller component
    components[rootB].clear();
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
        int type, a, b;
        cin >> type >> a >> b;
        if (type == 1) {
            unite(a, b);
        } else {
            int root = find(a);
            if (components[root].size() < b) {
                cout << -1 << '\n';
            } else {
                auto it = components[root].rbegin(); // reverse iterator for descending order
                advance(it, b - 1);
                cout << *it << '\n';
            }
        }
    }

    return 0;
}