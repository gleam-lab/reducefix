#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i=0; i<n; i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
using pi = pair<int, int>;

class UnionFind {
public:
    vector<int> parent, rank;
    UnionFind(int n) : parent(n), rank(n, 0) {
        rep(i, n) parent[i] = i;
    }

    int findRoot(int x) {
        if (parent[x] != x) parent[x] = findRoot(parent[x]);
        return parent[x];
    }

    bool unite(int x, int y) {
        int rx = findRoot(x), ry = findRoot(y);
        if (rx == ry) return false;
        if (rank[rx] < rank[ry]) {
            parent[rx] = ry;
        } else {
            parent[ry] = rx;
            if (rank[rx] == rank[ry]) rank[rx]++;
        }
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    UnionFind uf(n);
    vector<priority_queue<int>> pq(n);
    
    rep(qi, q) {
        int com;
        cin >> com;
        
        if (com == 1) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            
            int ru = uf.findRoot(u), rv = uf.findRoot(v);
            if (ru != rv) {
                uf.unite(ru, rv);
                
                // Merge the priority queues
                if (pq[ru].size() > pq[rv].size()) {
                    while (!pq[rv].empty()) {
                        pq[ru].push(pq[rv].top());
                        pq[rv].pop();
                    }
                } else {
                    while (!pq[ru].empty()) {
                        pq[rv].push(pq[ru].top());
                        pq[ru].pop();
                    }
                }
                
                // Update the root's priority queue
                pq[uf.findRoot(u)] = pq[ru];
                pq[uf.findRoot(v)] = pq[ru];
            }
        } else if (com == 2) {
            int v, k;
            cin >> v >> k;
            v--;
            
            int rv = uf.findRoot(v);
            if (pq[rv].size() < k) cout << "-1" << endl;
            else {
                auto it = pq[rv].begin();
                advance(it, k - 1);
                cout << *it << endl;
            }
        }
    }
    
    return 0;
}