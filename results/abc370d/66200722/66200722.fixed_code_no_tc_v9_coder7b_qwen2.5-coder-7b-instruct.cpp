#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define ff first
#define ss second
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);

const int N=4e5+7;
vector<pair<int,int>> adj[N];

void dfs(int node,int par,ll &cnt){
    cnt++;
    for(auto child:adj[node]){
        if(child.ff==par)continue;
        dfs(child.ff,node,cnt);
    }
}

int main(){
    fastio;
    int h,w,q;
    cin>>h>>w>>q;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            int u=i*w+j,v=(i+1)*w+j;
            if(u<w*h-1)adj[u].pb({v,i+1});
            if(v<w*h-1)adj[v].pb({u,i});
            if(j<w-1)adj[u].pb({u+1,i});
            if(j>0)adj[u].pb({u-1,i});
        }
    }

    while(q--){
        int x,y;
        cin>>x>>y;
        x--,y--;
        ll cnt=0;
        dfs(x*y,w,h,cnt);
        cout<<cnt<<"\n";
    }
    return 0;
}