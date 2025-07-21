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
    if(seen[x]&&x!=1) continue; // Only visit unvisited nodes or node 1
    if(x==1){
      if(hen!=1){
        ans=min(ans,hen+1);
      }
    } else {
      dfs(x,hen+1); // Pass the incremented hen value to the recursive call
    }
  }
  seen[n]=false; // Reset the seen status after recursion
}

int main(){
  ll n,m;
  cin>>n>>m;
  for(int i=0;i<m;i++){
    ll a,b;
    cin>>a>>b;
    if(a != b) { // Avoid adding self-loops which are not needed
      graph[a].push_back(b);
      graph[b].push_back(a); // Ensure bidirectional graph
    }
    if(!seen.count(a)) seen[a]=false;
    if(!seen.count(b)) seen[b]=false;
  }
  dfs(1,0);
  if(ans<inf) cout<<ans<<endl;
  else cout<<-1<<endl;
}