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
    int i = 0, j = 0;
    int n = uni[x].size(), m = uni[y].size();
    
    while(i < n && j < m && merged.size() < 10){
      if(uni[x][i] > uni[y][j]){
        merged.push_back(uni[x][i++]);
      }else{
        merged.push_back(uni[y][j++]);
      }
    }
    
    while(i < n && merged.size() < 10) merged.push_back(uni[x][i++]);
    while(j < m && merged.size() < 10) merged.push_back(uni[y][j++]);
    
    uni[x] = merged;
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
      b = b; // convert to 0-based k
      if(uf.uni[uf.root(a)].size() <= b){
        cout << -1 << endl;
      }
      else{
        cout << uf.uni[uf.root(a)][b] + 1 << endl;
      }
    }
  }
}