#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0;i<n;i++)
using P = pair<int,int>;
using T = tuple<int,int,int>;

struct Union_Find{
  
  vector<int> sz,par;
  vector<multiset<int>> top;
  
  Union_Find(int n){
    sz.resize(n,1);
    par.resize(n,-1);
    top.resize(n);
    rep(i,n) top[i].insert(i);
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
    for(auto val : top[y]){
      top[x].insert(val);
      if(top[x].size() > 10) top[x].erase(top[x].begin());
    }
  }
  
};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
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
      int r = uf.root(a);
      if(uf.top[r].size() < b+1){
        cout << -1 << endl;
      }
      else{
        auto it = uf.top[r].end();
        advance(it, - (b+1));
        cout << (*it) + 1 << endl;
      }
    }
  }
}