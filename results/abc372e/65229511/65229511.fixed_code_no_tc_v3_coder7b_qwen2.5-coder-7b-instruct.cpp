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
    UnionFind(int n) : parent(n), rank(n, 0) {
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
            parent[rx] = ry;
        } else {
            parent[ry] = rx;
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
    vector<vector<int>> adj(n);
    rep(i, n) adj[i].push_back(i);
    vector<int> ans;
    rep(qi, q) {
        int com;
        cin >> com;
        if(com==1) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            if(uf.findRoot(u)!=uf.findRoot(v)) {
                uf.unite(u, v);
                int ru = uf.findRoot(u);
                int rv = uf.findRoot(v);
                adj[ru].insert(adj[rv].begin(), adj[rv].end());
                adj[rv].clear();
            }
        }
        if(com==2) {
            int v, k;
            cin >> v >> k;
            v--;
            if(k>adj[v].size()) ans.push_back(-1);
            else {
                sort(all(adj[v]));
                ans.push_back(adj[v][k-1]+1);
            }
        }
    }
    for(auto x:ans) cout << x << endl;

    return 0;
}