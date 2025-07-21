#include<bits/stdc++.h>
using namespace std;
int parent[200005];
int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

int main() {
    int n, q;
    cin >> n >> q;
    
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
    }
    
    while (q--) {
        int op, u, v;
        cin >> op >> u >> v;
        
        if (op == 1) {
            int root_u = find(u);
            int root_v = find(v);
            if (root_u != root_v) {
                parent[root_u] = root_v;
            }
        } else if (op == 2) {
            int root_v = find(v);
            set<int> adj_vertices;
            for (int i = 1; i <= n; ++i) {
                if (find(i) == root_v) {
                    adj_vertices.insert(i);
                }
            }
            
            int k;
            cin >> k;
            if (adj_vertices.size() < k) {
                cout << -1 << endl;
            } else {
               cout << *(adj_vertices.rbegin() + (k - 1)) << endl;
            }
        }
    }
    
    return 0;
}