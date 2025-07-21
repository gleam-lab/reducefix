#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0;i<n;i++)
using P = pair<int,int>;
using T = tuple<int,int,int>;

struct Union_Find {
    vector<int> sz, par;
    vector<vector<int>> uni;

    Union_Find(int n) {
        sz.resize(n,1);
        par.resize(n,-1);
        uni.resize(n);
        rep(i,n) uni[i].emplace_back(i);
    }

    int root(int v) {
        if(par[v] == -1) return v;
        else return par[v] = root(par[v]);
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    void merge(int x, int y) {
        x = root(x), y = root(y);
        if(x == y) return;
        if(sz[x] < sz[y]) swap(x,y);
        par[y] = x;
        sz[x] += sz[y];
        
        // Merge the sorted lists
        vector<int> merged;
        merge(uni[x].rbegin(), uni[x].rend(), uni[y].rbegin(), uni[y].rend(), back_inserter(merged), greater<int>());
        if(merged.size() > 10) merged.resize(10);
        uni[x] = merged;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    Union_Find uf(n);

    rep(i,q) {
        int ty, a, b;
        cin >> ty >> a >> b;
        a--, b--;
        if(ty == 1) {
            if(!uf.issame(a, b))
                uf.merge(a, b);
        } else {
            int root = uf.root(a);
            if(uf.uni[root].size() < b+1) {
                cout << -1 << '\n';
            } else {
                cout << uf.uni[root][b] + 1 << '\n';
            }
        }
    }
}