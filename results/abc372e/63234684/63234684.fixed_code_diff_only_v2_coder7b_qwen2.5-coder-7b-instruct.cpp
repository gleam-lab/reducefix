#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0;i<n;i++)
using P = pair<int,int>;
using T = tuple<int,int,int>;

struct Union_Find{
  
  vector<int> sz,par;
  vector<multiset<int>> uni;
  
  Union_Find(int n){
    sz.resize(n,1);
    par.resize(n,-1);
    uni.resize(n);
    rep(i,n) uni[i].insert(i+1);
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
    if(y>x) swap(x,y);
    if(x == y) return;
    sz[x] += sz[y];
    sz[y] = 0;
    par[y] = x; 
    while(!uni[y].empty()){
      uni[x].insert(*uni[y].rbegin());
      uni[y].erase(prev(uni[y].end()));
    }
    auto it = prev(uni[x].end());
    while(it != uni[x].begin() && *it >= *prev(it)){
      it = prev(it);
    }
    while(uni[x].size() > 10) uni[x].erase(prev(uni[x].end()));
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
      if(uf.uni[uf.root(a)].size() < b){
        cout << -1 << endl;
      }
      else{
        cout << *(next(uf.uni[uf.root(a)].rbegin(),b-1)) << endl;
      }
    }
  }
}