#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0;i<n;i++)
using P = pair<int,int>;
using T = tuple<int,int,int>;

struct Union_Find {
    vector<int> par;
    vector<vector<int>> top;
    
    Union_Find(int n) {
        par.resize(n, -1);
        top.resize(n);
        rep(i,n) top[i].push_back(i);
    }
    
    int root(int v) {
        if(par[v] == -1) return v;
        return par[v] = root(par[v]);
    }
    
    void merge(int x, int y) {
        x = root(x), y = root(y);
        if(x == y) return;
        
        if(top[x].size() < top[y].size()) swap(x, y);
        
        vector<int> merged;
        merge(top[x].begin(), top[x].end(),
              top[y].begin(), top[y].end(),
              back_inserter(merged), greater<int>());
        
        top[x].clear();
        for(int i = 0; i < min(10, (int)merged.size()); i++) {
            top[x].push_back(merged[i]);
        }
        
        par[y] = x;
    }
    
    int query(int v, int k) {
        v = root(v);
        if(k > top[v].size()) return -1;
        return top[v][k-1] + 1;
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
            uf.merge(a, b);
        } else {
            cout << uf.query(a, b) << '\n';
        }
    }
}