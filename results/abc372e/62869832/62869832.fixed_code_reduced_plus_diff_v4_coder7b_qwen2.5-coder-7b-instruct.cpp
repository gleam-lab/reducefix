#include<bits/stdc++.h>
using namespace std;

struct UF {
    vector<int> parent, size;
    
    UF(int n) : parent(n), size(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }
    
    int find(int x) {
        if (parent[x] != x) 
            parent[x] = find(parent[x]);
        return parent[x];
    }
    
    void unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;
        if (size[x] < size[y]) swap(x, y);
        parent[y] = x;
        size[x] += size[y];
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    UF uf(n + 1);
    vector<multiset<int>> adj(n + 1);

    while (q--) {
        int type, u, v, k;
        cin >> type >> u >> v;

        if (type == 1) {
            int pu = uf.find(u), pv = uf.find(v);
            if (pu != pv) {
                // Merge sets
                multiset<int>& sa = adj[pu], &sb = adj[pv];
                sa.insert(sb.begin(), sb.end());
                sa.insert(v);
                sb.clear();
                uf.unite(u, v);
            }
        } else {
            int pu = uf.find(u);
            auto& s = adj[pu];
            if (s.size() < k) cout << "-1\n";
            else cout << *next(s.rbegin(), k - 1) << '\n';
        }
    }

    return 0;
}