#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0;i<n;i++)
using P = pair<int,int>;
using T = tuple<int,int,int>;

struct Union_Find{
  
  vector<int> sz,par;
  vector<vector<int>> uni;
  
  Union_Find(int n){
    sz.resize(n,1);
    par.resize(n,-1);
    uni.resize(n);
    rep(i,n) uni[i].emplace_back(i);
  }
  
  int root(int v){
    if(par[v] == -1) return v;
    else return par[v] = root(par[v]);
  }
  
  bool issame(int x,int y){
    return root(x) == root(y);
  }
  
  void merge(int x,int y){
    x = root(x),y = root(y);
    if(x == y) return;
    if(sz[x] < sz[y]) swap(x,y);
    sz[x] += sz[y];
    par[y] = x;
    
    vector<int> merged;
    merge(uni[x].rbegin(), uni[x].rend(),
          uni[y].rbegin(), uni[y].rend(),
          back_inserter(merged));
    reverse(merged.begin(), merged.end());
    if(merged.size() > 10) merged.resize(10);
    uni[x] = merged;
    uni[y].clear();
  }
  
};

int main(){
  int n,q;
  cin >> n >> q;
  Union_Find uf(n);
  
  rep(i,q){
    int ty,a,b;
    cin >> ty >> a >> b;
    a--,b--;
    if(ty == 1){
      uf.merge(a,b);
    }
    else{
      b = uf.uni[uf.root(a)].size() - b;
      if(b < 0 || b >= uf.uni[uf.root(a)].size()){
        cout << -1 << endl;
      }
      else{
        cout << uf.uni[uf.root(a)][b] + 1 << endl;
      }
    }
  }
}