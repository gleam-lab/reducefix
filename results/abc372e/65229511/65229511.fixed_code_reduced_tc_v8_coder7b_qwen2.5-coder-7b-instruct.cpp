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
            parent[rx] = ry;
            size[ry] += size[rx];
        } else {
            parent[ry] = rx;
            size[rx] += size[ry];
            if (rank[rx] == rank[ry])
                rank[rx]++;
        }
        return true;
    }
    int getSize(int x) {
        return size[findRoot(x)];
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    UnionFind uf(n);
    vector<vector<int>> cnt(n);
    rep(i, n) cnt[i].push_back(i + 1);
    vector<int> ans;
    rep(qi, q) {
        int com;
        cin >> com;
        if(com==1) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            int ru = uf.findRoot(u);
            int rv = uf.findRoot(v);
            if(ru!=rv) {
                if(uf.getSize(ru)<uf.getSize(rv)) swap(ru, rv);
                uf.unite(ru, rv);
                int rnew=uf.findRoot(ru);
                int rold=(rnew==ru ? rv:ru);
                for (int x:cnt[rv]) cnt[rnew].push_back(x);
                sort(all(cnt[rnew]));
                cnt[rold].clear();
            }
        }
        if(com==2) {
            int v, k;
            cin >> v >> k;
            v--;
            if(k > uf.getSize(uf.findRoot(v))) ans.push_back(-1);
            else {
                ans.push_back(cnt[uf.findRoot(v)][uf.getSize(uf.findRoot(v))-k]);
            }
        }
    }
    for(auto x:ans) cout << x << endl;

    return 0;
}