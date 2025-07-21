#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int K_MAX = 10;

int parent[MAXN];
set<int, greater<int>> component[MAXN]; // Store up to K_MAX largest elements

// Find with path compression
int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

// Merge two components
void unite(int u, int v) {
    int root_u = find(u);
    int root_v = find(v);
    
    if (root_u == root_v)
        return;

    // Merge smaller set into larger one for efficiency
    if (component[root_u].size() < component[root_v].size()) {
        swap(root_u, root_v);
    }

    // Move top K_MAX elements from root_v to root_u
    for (auto it = component[root_v].begin(); 
         it != component[root_v].end() && component[root_u].size() < K_MAX; ++it) {
        component[root_u].insert(*it);
    }
    
    parent[root_v] = root_u;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N, Q;
    cin >> N >> Q;

    // Initialize DSU and components
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        component[i].insert(i); // Each vertex is its own component initially
    }

    while (Q--) {
        int op;
        cin >> op;

        if (op == 1) {
            int u, v;
            cin >> u >> v;
            unite(u, v);
        } else {
            int v, k;
            cin >> v >> k;
            int root = find(v);
            
            if (k > (int)component[root].size()) {
                cout << -1 << '\n';
            } else {
                auto it = component[root].begin();
                advance(it, k - 1);
                cout << *it << '\n';
            }
        }
    }

    return 0;
}