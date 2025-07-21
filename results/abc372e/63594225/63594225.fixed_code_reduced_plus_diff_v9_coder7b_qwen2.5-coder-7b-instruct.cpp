#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

struct DSU {
    vector<int> parent, rank;
    DSU(int n) {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
        rank.assign(n + 1, 1);
    }
    
    int find(int u) {
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }
    
    void merge(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return;
        if (rank[u] < rank[v]) swap(u, v);
        parent[v] = u;
        if (rank[u] == rank[v]) ++rank[u];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, q;
    cin >> n >> q;
    
    DSU dsu(n + 1);
    
    while (q--) {
        int type, u, v;
        cin >> type >> u >> v;
        
        if (type == 1) {
            dsu.merge(u, v);
        } else {
            u = dsu.find(u);
            set<int> s;
            for (int i = 1; i <= n; ++i) {
                if (dsu.find(i) == u) s.insert(i);
            }
            auto it = s.rbegin();
            if (it == s.rend() || *it < v) cout << "-1\n";
            else {
                for (int i = 0; i < v - 1; ++i) ++it;
                cout << *it << "\n";
            }
        }
    }
    
    return 0;
}