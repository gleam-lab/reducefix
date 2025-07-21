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
    vector<int> parent, rank, size;
    UnionFind(int n) : parent(n), rank(n, 0), size(n, 1) {
        for (int i = 0; i < n; i++) 
            parent[i] = i;
    }
    int findRoot(int x) {
        if (parent[x] != x) 
            parent[x] = findRoot(parent[x]);
        return parent[x];
    }
    bool unite(int x, int y) {
        int rx = findRoot(x), ry = findRoot(y);
        if (rx == ry) return false;
        if (rank[rx] < rank[ry]) {
            parent[ry] = rx;
            size[rx] += size[ry];
        } else {
            parent[rx] = ry;
            size[ry] += size[rx];
            if (rank[rx] == rank[ry])
            rank[rx]++;
        }
        return true;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    UnionFind uf(n);
    vector<set<int>> components(n);
    for(int i = 0; i < n; ++i) {
        components[i].insert(i);
    }

    vector<int> ans;
    
    while(q--) {
        int type;
        cin >> type;
        if(type == 1) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            int ru = uf.findRoot(u);
            int rv = uf.findRoot(v);
            if(ru != rv) {
                // Always merge smaller into larger
                if(components[ru].size() < components[rv].size()) {
                    swap(ru, rv);
                }
                // Merge rv into ru
                for(int x : components[rv]) {
                    components[ru].insert(x);
                }
                components[rv].clear();
                uf.unite(ru, rv);
            }
        } else {
            int v, k;
            cin >> v >> k;
            v--;
            int root = uf.findRoot(v);
            if(components[root].size() < k) {
                ans.push_back(-1);
            } else {
                auto it = components[root].rbegin();
                advance(it, k-1);
                ans.push_back(*it + 1);
            }
        }
    }

    for(int x : ans) {
        cout << x << "\n";
    }

    return 0;
}