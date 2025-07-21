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
    vector<set<int>> cnt(n);
    rep(i, n) cnt[i].insert(i+1);  // Store vertices as 1-based
    vector<int> ans;
    rep(qi, q) {
        int com;
        cin >> com;
        if(com==1) {
            int u, v;
            cin >> u >> v;
            int ru = uf.findRoot(u-1);
            int rv = uf.findRoot(v-1);
            if(ru != rv) {
                if(cnt[ru].size() < cnt[rv].size()) swap(ru, rv);
                uf.parent[rv] = ru;
                cnt[ru].insert(all(cnt[rv]));
                cnt[rv].clear();
            }
        }
        if(com==2) {
            int v, k;
            cin >> v >> k;
            int root = uf.findRoot(v-1);
            if(cnt[root].size() < k) ans.push_back(-1);
            else {
                auto it = cnt[root].rbegin();
                advance(it, k-1);
                ans.push_back(*it);
            }
        }
    }
    for(auto x:ans) cout << x << endl;
    return 0;
}