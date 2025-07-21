#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0;i<n;i++)
#define all(v) v.begin(),v.end()
using P = pair<int,int>;
using T = tuple<int,int,int>;

struct Union_Find {
    vector<int> par;
    vector<vector<int>> uni;
    
    Union_Find(int n) {
        par.resize(n, -1);
        uni.resize(n);
        rep(i,n) uni[i].push_back(i);
    }
    
    int root(int v) {
        if(par[v] == -1) return v;
        return par[v] = root(par[v]);
    }
    
    bool issame(int x, int y) {
        return root(x) == root(y);
    }
    
    void merge(int x, int y) {
        x = root(x), y = root(y);
        if(x == y) return;
        if(uni[x].size() < uni[y].size()) swap(x, y);
        par[y] = x;
        uni[x].insert(uni[x].end(), all(uni[y]));
        uni[y].clear();
        sort(all(uni[x]), greater<int>());
        if(uni[x].size() > 10) uni[x].resize(10);
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
            int r = uf.root(a);
            if(uf.uni[r].size() < b) {
                cout << -1 << "\n";
            } else {
                cout << uf.uni[r][b-1] + 1 << "\n";
            }
        }
    }
}