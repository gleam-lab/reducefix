#include<bits/stdc++.h>
using namespace std;
using ll=long long;
map<ll,vector<ll>>graph;
map<ll,bool>seen;
const ll inf=1LL<<60;
ll ans=inf;
void dfs(ll n,ll hen){
  seen[n]=true;
  for(auto x:graph[n]){
    if(x!=1&&seen[x])continue;
    if(x==1){
      if(hen!=1){
        ans=min(ans,hen);
      }
      continue;
    }
    dfs(x,hen-1);
  }
}
int main(){
  ll n,m;
  cin>>n>>m;
  for(int i=0;i<m;i++){
    ll a,b;
    cin>>a>>b;
    graph[a].push_back(b);
    graph[b].push_back(a); // Add bidirectional edge
  }
  dfs(1,2); // Start DFS from node 1 with hen = 2
  if(ans!=inf)cout<<ans<<endl;
  else cout<<-1<<endl;
}