#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
using pi = pair<int, int>;
const int di[]={1,-1,0,0};
const int dj[]={0,0,1,-1};
const int INF=1e9;

struct UnionFind {
    vector<int> parent, rank;
    vector<set<int>> components;
    
    UnionFind(int n) : parent(n), rank(n, 0), components(n) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            components[i].insert(i);
        }
    }
    
    int findRoot(int x) {
        if (parent[x] != x) 
            parent[x] = findRoot(parent[x]);
        return parent[x];
    }
    
    void unite(int x, int y) {
        int rx = findRoot(x), ry = findRoot(y);
        if (rx == ry) return;
        
        if (rank[rx] < rank[ry]) {
            parent[rx] = ry;
            components[ry].insert(all(components[rx]));
            components[rx].clear();
        } else {
            parent[ry] = rx;
            components[rx].insert(all(components[ry]));
            components[ry].clear();
            if (rank[rx] == rank[ry])
                rank[rx]++;
        }
    }
    
    int kthLargest(int v, int k) {
        int root = findRoot(v);
        if ((int)components[root].size() < k)
            return -2;
        
        auto it = components[root].rbegin();
        advance(it, k-1);
        return *it;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;
    UnionFind uf(n);
    vector<int> ans;
    
    rep(qi, q) {
        int com;
        cin >> com;
        if (com == 1) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            uf.unite(u, v);
        } else if (com == 2) {
            int v, k;
            cin >> v >> k;
            v--;
            ans.push_back(uf.kthLargest(v, k));
        }
    }
    
    for (auto x : ans) 
        cout << (x == -2 ? -1 : x + 1) << '\n';
    
    return 0;
}