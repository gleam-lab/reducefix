#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cassert>

using namespace std;

const int MAXN = 2e5 + 10;

int parent[MAXN];
set<int> adjacencySets[MAXN];

int findSet(int u) {
    if (parent[u] == u) return u;
    return parent[u] = findSet(parent[u]);
}

void unionSets(int u, int v) {
    u = findSet(u);
    v = findSet(v);
    if (u != v) {
        if (adjacencySets[u].size() > adjacencySets[v].size()) swap(u, v);
        for (int neighbor : adjacencySets[u]) {
            adjacencySets[v].insert(neighbor);
        }
        parent[u] = v;
    }
}

int kthLargest(int u, int k) {
    u = findSet(u);
    if (k <= adjacencySets[u].size()) {
        auto it = adjacencySets[u].rbegin();
        advance(it, k - 1);
        return *it;
    } else {
        return -1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;
    
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
    }
    
    while (q--) {
        int type;
        cin >> type;
        
        if (type == 1) {
            int u, v;
            cin >> u >> v;
            unionSets(u, v);
        } else if (type == 2) {
            int u, k;
            cin >> u >> k;
            cout << kthLargest(u, k) << "\n";
        }
    }
    
    return 0;
}