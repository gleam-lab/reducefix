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
            if(hen<ans) ans=hen; // Consider the distance to the node with value 1 as 0 (like a starting node)
        } else {
            dfs(x,hen+1);
        }
    }
}

int main(){
    ll n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        ll a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a); // Assuming the graph is undirected
        if(!seen.count(a))seen[a]=false;
        if(!seen.count(b))seen[b]=false;
    }
    // Starting the DFS from node 1, assuming it's in the graph
    dfs(1,0);
    if(ans==inf)cout<<-1<<endl;
    else cout<<ans<<endl;
}