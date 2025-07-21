#include<bits/stdc++.h>
using namespace std;
using ll=long long;
map<ll,vector<ll>>graph;
vector<bool>seen;
const ll inf=1LL<<60;
ll ans=inf;
void dfs(ll n,ll hen){
    seen[n]=true;
    for(auto x:graph[n]){
        if(!seen[x] && x != 1){
            dfs(x, hen + 1);
        } else if(x == 1) {
            ans = min(ans, hen);
        }
    }
}
int main(){
    ll n,m;
    cin>>n>>m;
    graph.resize(n+1);
    seen.resize(n+1, false);
    for(ll i=0;i<m;i++){
        ll a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1, 0);
    if(ans == inf) cout << -1 << endl;
    else cout << ans << endl;
}