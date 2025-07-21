#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int K_MAX = 10;

int parent[MAXN];
set<int, greater<int>> group[MAXN]; // Store top K nodes in descending order

// Find representative with path compression
int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

// Merge two sets: small-to-large heuristic
void unite(int u, int v) {
    int rootU = find(u);
    int rootV = find(v);
    
    if (rootU == rootV)
        return;
        
    // Always merge smaller set into larger one
    if (group[rootU].size() < group[rootV].size())
        swap(rootU, rootV);
        
    // Merge the elements from group[rootV] to group[rootU]
    for (int val : group[rootV]) {
        group[rootU].insert(val);
        if (group[rootU].size() > K_MAX) {
            auto it = group[rootU].end();
            --it;
            group[rootU].erase(it);
        }
    }
    
    parent[rootV] = rootU;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;
    
    // Initialize DSU and group data structure
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        group[i].insert(i);
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
            
            if (k > group[root].size()) {
                cout << -1 << '\n';
            } else {
                auto it = group[root].begin();
                advance(it, k - 1);
                cout << *it << '\n';
            }
        }
    }
    
    return 0;
}