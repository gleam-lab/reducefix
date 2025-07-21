#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int TOP_K = 10;

int parent[MAXN];
set<int, greater<int>> component[MAXN]; // Store top 10 largest nodes in each component

// Find with path compression
int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

// Merge two sets ensuring only root nodes are passed
void unite(int u, int v) {
    // Always merge smaller set into larger one to optimize performance
    if (component[u].size() < component[v].size())
        swap(u, v);
    
    // Merge component v into u
    for (auto val : component[v]) {
        component[u].insert(val);
        if (component[u].size() > TOP_K)
            component[u].erase(--component[u].end());
    }
    
    parent[v] = u;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;
    
    // Initialize
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        component[i].insert(i);
    }
    
    while (Q--) {
        int type;
        cin >> type;
        
        if (type == 1) {
            int u, v;
            cin >> u >> v;
            
            int pu = find(u);
            int pv = find(v);
            
            if (pu != pv)
                unite(pu, pv);
        } else {
            int v, k;
            cin >> v >> k;
            
            int pv = find(v);
            
            // Get the k-th largest
            if (component[pv].size() < k) {
                cout << -1 << "\n";
            } else {
                auto it = component[pv].begin();
                advance(it, k - 1);
                cout << *it << "\n";
            }
        }
    }
    
    return 0;
}