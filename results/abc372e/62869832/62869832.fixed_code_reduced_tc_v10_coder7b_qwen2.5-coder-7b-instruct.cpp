#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, rank, size, pqIndex;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    DSU(int n) : parent(n + 1), rank(n + 1, 0), size(n + 1, 1), pqIndex(n + 1, -1) {
        iota(parent.begin(), parent.end(), 0);
    }
    
    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }
    
    void unite(int u, int v) {
        u = find(u);
        v = find(v);
        
        if (u == v) return;
        
        if (rank[u] > rank[v]) {
            swap(u, v);
        } else if (rank[u] == rank[v]) {
            rank[v]++;
        }
        
        parent[u] = v;
        size[v] += size[u];
        
        // Update priority queue for set u
        pq.erase(pq.begin() + pqIndex[u]);
        pq.push({size[u], u});
        pqIndex[u] = pq.size() - 1;
        
        // Update priority queue for set v
        pq.push({size[v], v});
        pqIndex[v] = pq.size() - 1;
    }
    
    int getKthLargest(int u, int k) {
        u = find(u);
        auto it = pq.lower_bound({k, 0});
        if (it != pq.end() && (*it).first >= k) {
            return (*it).second;
        }
        return -1;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;
    
    DSU dsu(n);
    
    while (q--) {
        int op, ix, iy;
        cin >> op >> ix >> iy;
        
        if (op == 1) {
            dsu.unite(ix, iy);
        } else {
            cout << dsu.getKthLargest(ix, iy) << "\n";
        }
    }
    
    return 0;
}