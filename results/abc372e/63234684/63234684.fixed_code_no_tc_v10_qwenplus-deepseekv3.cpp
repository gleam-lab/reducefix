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
    uni[x].insert(uni[x].end(), uni[y].begin(), uni[y].end());
    sort(uni[x].rbegin(), uni[x].rend());
    if(uni[x].size() > 10) uni[x].resize(10);
  }
  
};

int main(){
  int n,q;
  cin >> n >> q;
  Union_Find uf(n);
  
  rep(i,q){
    int ty,a,b;
    cin >> ty >> a >> b;
    a--; // Convert to 0-based index
    if(ty == 1){
      int v = b-1; // Convert to 0-based index
      uf.merge(a,v);
    }
    else{
      int k = b; // k is 1-based
      int root_a = uf.root(a);
      if(uf.uni[root_a].size() < k){
        cout << -1 << endl;
      }
      else{
        cout << uf.uni[root_a][k-1] + 1 << endl; // Convert back to 1-based index
      }
    }
  }
}