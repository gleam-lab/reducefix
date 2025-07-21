#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int parent[MAXN];
set<int> components[MAXN];

int find(int x) {
    if (parent[x] != x)
        return find(parent[x]);
    return x;
}

void unite(int u, int v) {
    int rootU = find(u);
    int rootV = find(v);
    
    if (rootU == rootV)
        return;
        
    // Merge smaller set into larger set to keep tree depth low
    if (components[rootU].size() < components[rootV].size())
        swap(rootU, rootV);
        
    for (int node : components[rootV]) {
        components[rootU].insert(node);
        parent[node] = rootU;
    }
    components[rootV].clear();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

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
        } else if (type == 2) {
            int v, k;
            cin >> v >> k;
            int root = find(v);
            
            if (components[root].size() < k) {
                cout << -1 << "\n";
            } else {
                auto it = components[root].rbegin();  // reverse iterator for descending order
                for (int i = 0; i < k - 1; ++i) ++it;
                cout << *it << "\n";
            }
        }
    }

    return 0;
}