#include<bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent, rank;
    
    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for(int i = 1; i <= n; ++i) parent[i] = i;
    }

    int find(int u) {
        if(parent[u] != u) parent[u] = find(parent[u]);
        return parent[u];
    }

    void unite(int u, int v) {
        int pu = find(u), pv = find(v);
        if(pu == pv) return;
        
        if(rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else if(rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else {
            parent[pu] = pv;
            rank[pv]++;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, q; cin >> n >> q;
    DSU dsu(n);

    priority_queue<int, vector<int>, greater<int>> pq[n+1];

    while(q--) {
        int type; cin >> type;
        if(type == 1) {
            int u, v; cin >> u >> v;
            dsu.unite(u, v);
            pq[u].push(v);
            pq[v].push(u);
        } else {
            int v, k; cin >> v >> k;
            v = dsu.find(v);
            if(k > pq[v].size()) cout << -1 << '\n';
            else {
                auto it = pq[v].end(); advance(it, -k);
                cout << *it << '\n';
            }
        }
    }
    return 0;
}