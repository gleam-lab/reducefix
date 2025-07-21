#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0;i<n;i++)
using P = pair<int,int>;
using T = tuple<int,int,int>;

struct Union_Find{
    vector<int> sz, par;
    vector<multiset<int>> uni;

    Union_Find(int n){
        sz.resize(n, 1);
        par.resize(n, -1);
        uni.resize(n);
        rep(i,n) uni[i].insert(i);
    }

    int root(int v){
        if(par[v] == -1) return v;
        else return par[v] = root(par[v]);
    }

    bool issame(int x, int y){
        return root(x) == root(y);
    }

    void merge(int x, int y){
        x = root(x), y = root(y);
        if(x == y) return;
        if(sz[x] < sz[y]) swap(x, y);
        sz[x] += sz[y];
        par[y] = x;
        for(auto v : uni[y]){
            uni[x].insert(v);
        }
        uni[y].clear();
        while(uni[x].size() > 10){
            auto it = uni[x].begin();
            uni[x].erase(it);
        }
    }

    int query(int v, int k){
        v = root(v);
        if(uni[v].size() < k) return -1;
        auto it = uni[v].end();
        advance(it, -k);
        return *it + 1;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;
    Union_Find uf(n);
    
    rep(i,q){
        int ty, a, b;
        cin >> ty >> a >> b;
        a--, b--;
        if(ty == 1){
            uf.merge(a, b);
        }
        else{
            cout << uf.query(a, b) << '\n';
        }
    }
}