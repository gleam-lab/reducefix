#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,mn=LLONG_MAX,vis[200005];
vector<int> b[200005];
void dfs(int x,ll cnt){
    vis[x]=1;
    ll ans=cnt+1;
    bool found=false;
    for(int i=0;i<b[x].size();i++){
        if(vis[b[x][i]]==0){
            dfs(b[x][i],ans);
            found=true;
        }
    }
    if(!found){
        mn=min(mn,ans);
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        b[u].push_back(v);
    }
    dfs(1,0);
    if(mn==LLONG_MAX){
        cout<<-1;
    }
    else{
        cout<<mn;
    }
    return 0;
}