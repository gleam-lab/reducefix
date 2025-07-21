#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

#define pb push_back

const int MAXN = 2 * 1e5 + 5;

int parent[MAXN];
set<int> components[MAXN];

int find(int u) {
    if (parent[u] != u)
        parent[u] = find(parent[u]);
    return parent[u];
}

void unite(int u, int v) {
    int rootU = find(u);
    int rootV = find(v);
    
    if (rootU == rootV)
        return;
        
    // Always merge smaller component into larger one for efficiency
    if (components[rootU].size() < components[rootV].size())
        swap(rootU, rootV);
        
    // Merge the smaller set into the larger one
    for (int node : components[rootV]) {
        components[rootU].insert(node);
    }
    
    // Update parent
    parent[rootV] = rootU;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N, Q;
    cin >> N >> Q;
    
    // Initialize DSU
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        components[i].insert(i);
    }
    
    while (Q--) {
        int type;
        cin >> type;
        
        if (type == 1) {
            int u, v;
            cin >> u >> v;
            unite(u, v);
        } 
        else if (type == 2) {
            int v, k;
            cin >> v >> k;
            
            int root = find(v);
            
            if (components[root].size() < (size_t)k) {
                cout << -1 << "\n";
            } else {
                // Get k-th largest using reverse iterator
                auto it = components[root].end();
                advance(it, -k);
                cout << *it << "\n";
            }
        }
    }
    
    return 0;
}