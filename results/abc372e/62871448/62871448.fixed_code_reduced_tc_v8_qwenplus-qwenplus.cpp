#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int K_MAX = 10;

int N, Q;
int parent[MAXN];
set<int> component[MAXN]; // Store top 10 nodes in descending order

// Find root with path compression
int find(int x) {
    if (x != parent[x]) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

// Merge two sets ensuring each set stores at most K_MAX largest elements
void unite(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx == fy) return;
    
    // Always merge smaller into larger
    if (component[fx].size() < component[fy].size()) swap(fx, fy);
    
    // Transfer all elements from fy to fx
    for (auto it : component[fy]) {
        component[fx].insert(it);
        if (component[fx].size() > K_MAX) {
            component[fx].erase(prev(component[fx].end()));
        }
    }
    
    // Clear the smaller set
    component[fy].clear();
    parent[fy] = fx;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N >> Q;
    
    // Initialize DSU and components
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
            unite(u, v);
        } else if (type == 2) {
            int v, k;
            cin >> v >> k;
            int root = find(v);
            
            if (component[root].size() < k) {
                cout << -1 << '\n';
            } else {
                auto it = component[root].end();
                advance(it, -k);
                cout << *it << '\n';
            }
        }
    }
    
    return 0;
}