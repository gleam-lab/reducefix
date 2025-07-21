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
    int rootA = find(a);
    int rootB = find(b);
    
    if(rootA == rootB)
        return;
        
    // Merge smaller into larger for better performance
    if(components[rootA].size() < components[rootB].size())
        swap(rootA, rootB);
        
    // Move all elements from rootB to rootA
    for(int node : components[rootB]) {
        components[rootA].insert(node);
        parent[node] = rootA;
    }
    
    // Clear component B to free memory
    components[rootB].clear();
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    
    components.resize(n+1);
    parent.resize(n+1);
    
    for(int i = 1; i <= n; ++i) {
        parent[i] = i;
        components[i].insert(i);
    }

    while(q--) {
        int type;
        cin >> type;
        
        if(type == 1) {
            int u, v;
            cin >> u >> v;
            unite(u, v);
        } else {
            int v, k;
            cin >> v >> k;
            
            int root = find(v);
            
            // Use reverse iterator to get k-th largest
            auto it = components[root].rbegin();
            int count = 0;
            
            while(it != components[root].rend() && count < k - 1) {
                ++it;
                ++count;
            }
            
            if(it == components[root].rend()) {
                cout << -1 << '\n';
            } else {
                cout << *it << '\n';
            }
        }
    }

    return 0;
}