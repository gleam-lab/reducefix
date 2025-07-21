#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define ff first
#define ss second
#define sz(x) ((int)((x).size()))
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define ii pair<int,int>
#define vii vector<pair<int,int>>

const int mod=1e9+7;
const int INF = 1e9 + 7;
const int MX = 1e5 + 5;

int n,m,q,x,y;
vector<vii> g,v;

void dfs(int u){
    v[u][0]=true;
    for(auto [to,w]:g[u]){
        if(!v[to][0]){
            dfs(to);
        }
    }
}

int main(){
    IOS;
    cin>>n>>m>>q;
    g.resize(n+1);
    v.resize(n+1,vector<bool>(2,false));
    
    while(q--){
        cin>>x>>y;
        g[x].pb({y,0});
        g[y].pb({x,0});
    }

    dfs(1);

    int ans=n*m;
    for(int i=1;i<=n;++i){
        for(int j=0;j<m;++j){
            if(g[i][j].ss==0 && !v[i][1]){
                ans-=sz(g[i]);
                break;
            }
        }
    }
    
    cout<<ans<<endl;
    return 0;
}