#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
using pi = pair<int, int>;
const int INF=1e9;
struct UnionFind {
    vector<int> parent, rank;
    vector<multiset<int>> top;
    UnionFind(int n) : parent(n), rank(n, 0), top(n) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            top[i].insert(i);
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
            for (int num : top[rx]) {
                top[ry].insert(num);
                if (top[ry].size() > 10)
                    top[ry].erase(top[ry].begin());
            }
            top[rx].clear();
        } else {
            parent[ry] = rx;
            for (int num : top[ry]) {
                top[rx].insert(num);
                if (top[rx].size() > 10)
                    top[rx].erase(top[rx].begin());
            }
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
            if ((int)uf.top[root].size() < k) {
                ans.push_back(-1);
            } else {
                auto it = uf.top[root].rbegin();
                advance(it, k-1);
                ans.push_back(*it + 1);
            }
        }
    }
    for(auto x : ans) cout << x << endl;
    return 0;
}