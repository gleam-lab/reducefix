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
    sz[y] = 0;
    par[y] = x;
    while(uni[y].size() > 0){
      uni[x].push_back(uni[y].back());
      uni[y].pop_back();
    }
    // Sort the list of vertices for the component rooted at x
    sort(uni[x].rbegin(), uni[x].rend());
    // Ensure that the merged component has the correct number of vertices
    while(uni[x].size() > 9) uni[x].pop_back();
  }
  
  // Return the sorted list of vertices for the component rooted at v
  vector<int> get_component(int v){
    int r = root(v);
    return uni[r];
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
      vector<int> comp = uf.get_component(b);
      if(comp.size() <= b) cout << -1 << endl;
      else cout << comp[b] + 1 << endl;
    }
  }
}