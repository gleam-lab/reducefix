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
        if(seen[x] && x != n) continue; // Avoid revisiting same node except for back Edges
        if(x==1){
            if(hen>0 && hen < ans) ans=hen;
        } else {
            dfs(x,hen+1);
        }
    }
    seen[n]=false; // Reset seen for other DFS calls
}
int main(){
    ll n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        ll a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a); // Ensure bidirectional edges for DFS to work correctly
        seen[a]=false;
        seen[b]=false;
    }
    dfs(1,0);
    if(ans!=inf)cout<<ans<<endl;
    else cout<<-1<<endl;
}