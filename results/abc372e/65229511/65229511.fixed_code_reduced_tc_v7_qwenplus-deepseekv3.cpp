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
            components[ry].insert(components[rx].begin(), components[rx].end());
            components[rx].clear();
        } else {
            parent[ry] = rx;
            components[rx].insert(components[ry].begin(), components[ry].end());
            components[ry].clear();
            if (rank[rx] == rank[ry])
                rank[rx]++;
        }
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    UnionFind uf(n);
    vector<int> ans;
    rep(qi, q) {
        int com;
        cin >> com;
        if(com==1) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            uf.unite(u, v);
        }
        if(com==2) {
            int v, k;
            cin >> v >> k;
            v--;
            int root = uf.findRoot(v);
            if((int)uf.components[root].size() < k) {
                ans.push_back(-1);
            } else {
                auto it = uf.components[root].rbegin();
                advance(it, k-1);
                ans.push_back(*it + 1);
            }
        }
    }
    for(auto x:ans) cout << x << endl;
    return 0;
}