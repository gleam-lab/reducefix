#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int K_MAX = 10;

int parent[MAXN];
set<int, greater<int>> component[MAXN]; // Store top 10 elements in descending order

// Find with path compression
int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int u, int v) {
    int root_u = find(u);
    int root_v = find(v);
    
    if (root_u == root_v)
        return;
        
    // Merge smaller component into larger one (union by size)
    if (component[root_u].size() < component[root_v].size()) {
        swap(root_u, root_v);
        swap(u, v);
    }
    
    // Merge the two sets
    for (auto val : component[root_v]) {
        component[root_u].insert(val);
        if (component[root_u].size() > K_MAX) {
            auto it = component[root_u].end();
            --it;
            component[root_u].erase(it);
        }
    }
    
    // Update parent
    parent[root_v] = root_u;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
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
        } else {
            int v, k;
            cin >> v >> k;
            
            int root = find(v);
            
            if (k > component[root].size()) {
                cout << -1 << '\n';
            } else {
                auto it = component[root].begin();
                advance(it, k-1);
                cout << *it << '\n';
            }
        }
    }
    
    return 0;
}