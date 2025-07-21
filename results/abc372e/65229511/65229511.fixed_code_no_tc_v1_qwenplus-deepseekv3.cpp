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
    vector<set<int>>* sets;
    UnionFind(int n, vector<set<int>>& s) : parent(n), rank(n, 0), sets(&s) {
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int findRoot(int x) {
        if (parent[x] != x)
            parent[x] = findRoot(parent[x]);
        return parent[x];
    }
    void unite(int x, int y) {
        int rx = findRoot(x), ry = findRoot(y);
        if (rx == ry) return;
        if (rank[rx] < rank[ry]) swap(rx, ry);
        parent[ry] = rx;
        if (rank[rx] == rank[ry])
            rank[rx]++;
        // Merge the smaller set into the larger one
        if ((*sets)[rx].size() < (*sets)[ry].size())
            swap(rx, ry);
        (*sets)[rx].insert((*sets)[ry].begin(), (*sets)[ry].end());
        (*sets)[ry].clear();
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<set<int>> cnt(n);
    rep(i, n) cnt[i].insert(i+1); // Store 1-based indices
    UnionFind uf(n, cnt);
    vector<int> ans;
    rep(qi, q) {
        int com;
        cin >> com;
        if(com==1) {
            int u, v;
            cin >> u >> v;
            uf.unite(u-1, v-1); // Convert to 0-based
        }
        else if(com==2) {
            int v, k;
            cin >> v >> k;
            v--;
            int root = uf.findRoot(v);
            if((int)cnt[root].size() < k) ans.push_back(-1);
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