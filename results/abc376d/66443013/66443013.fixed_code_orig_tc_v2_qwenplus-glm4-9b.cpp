#include<bits/stdc++.h>
using namespace std;
using ll=long long;
map<ll,vector<ll>>graph;
map<ll,bool>seen;
const ll inf=1LL<<60;
ll ans=inf;

void dfs(ll n,ll hen,ll count){
    seen[n]=true;
    if(count == 2){ // Check if we have used two edges from the set {1, ..., n}
        for(auto x:graph[n]){
            if(!seen[x]) dfs(x,hen+1,0); // Reset count for each new node
        }
    } else {
        for(auto x:graph[n]){
            if(x!=1 && !seen[x]) dfs(x,hen+1,count+1);
            if(x==1 && hen != 1){ // Check if we can use an edge to go back to the root
                ans = min(ans, hen + 1);
            }
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
    }
    dfs(1,0,0);
    if(ans == inf) cout << "-1" << endl;
    else cout << ans << endl;
}