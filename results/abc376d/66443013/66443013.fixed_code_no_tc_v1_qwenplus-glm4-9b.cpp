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
        if(x==1){
            if(hen>0 && hen<ans){
                ans=hen;
            }
            continue;
        }
        if(!seen[x]){
            dfs(x,hen+1);
        }
    }
}

int main(){
    ll n,m;
    cin>>n>>m;
    for(ll i=0;i<m;i++){
        ll a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        if(!seen.count(a))seen[a]=false;
        if(!seen.count(b))seen[b]=false;
    }
    dfs(1,0);
    if(ans==inf)cout<<-1<<endl;
    else cout<<ans<<endl;
}