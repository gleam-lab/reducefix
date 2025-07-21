#include<bits/stdc++.h>
using namespace std;
using ll=long long;
map<ll,vector<ll>>graph;
map<ll,bool>seen;
const ll inf=1LL<<60;
ll ans=inf;

void dfs(ll n, ll hen){
  if(seen[n]) return; // Avoid revisiting nodes to prevent infinite loops
  seen[n] = true;
  for(auto x : graph[n]){
    if(x == 1){
      ans = min(ans, hen + (n != 1)); // If we reach node 1, update answer considering if n is not already 1
      continue;
    }
    dfs(x, hen + 1);
  }
}

int main(){
  ll n, m;
  cin >> n >> m;
  for(int i = 0; i < m; i++){
    ll a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a); // Assuming undirected graph
  }
  dfs(1, 0);
  if(ans != inf) cout << ans << endl;
  else cout << "-1" << endl;
}