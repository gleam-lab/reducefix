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
    vector<vector<int>> top; // Stores up to 10 largest vertices in each component
    UnionFind(int n) : parent(n), rank(n, 0), top(n) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            top[i].push_back(i);
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
            top[ry].insert(top[ry].end(), all(top[rx]));
            sort(rall(top[ry]));
            if (top[ry].size() > 10) top[ry].resize(10);
            top[rx].clear();
        } else {
            parent[ry] = rx;
            top[rx].insert(top[rx].end(), all(top[ry]));
            sort(rall(top[rx]));
            if (top[rx].size() > 10) top[rx].resize(10);
            top[ry].clear();
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
            if(uf.top[root].size() < k) {
                ans.push_back(-1);
            } else {
                ans.push_back(uf.top[root][k-1] + 1);
            }
        }
    }
    for(auto x:ans) cout << x << endl;
    return 0;
}