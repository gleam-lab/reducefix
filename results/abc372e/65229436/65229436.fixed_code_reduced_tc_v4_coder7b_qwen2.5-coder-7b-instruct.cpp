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
    vector<priority_queue<int,vector<int>,greater<int>>> cnt(n);
    rep(i, n) cnt[i].push(i+1);
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
                if(cnt[ru].size()<cnt[rv].size()) swap(ru, rv);
                uf.unite(ru, rv);
                int rnew=uf.findRoot(ru);
                while(!cnt[rv].empty()){
                    cnt[rnew].push(cnt[rv].top());
                    cnt[rv].pop();
                }
                cnt[rv].clear();
            }
        }
        if(com==2) {
            int v, k;
            cin >> v >> k;
            v--;
            if(cnt[uf.findRoot(v)].size()<k) ans.push_back(-1);
            else {
                ans.push_back(cnt[uf.findRoot(v)].kth_element(k));
            }
        }
    }
    for(auto x:ans) cout << x << endl;

    return 0;
}