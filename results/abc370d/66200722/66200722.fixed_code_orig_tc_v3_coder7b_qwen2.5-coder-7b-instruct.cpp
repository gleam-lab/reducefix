#include<bits/stdc++.h>
using namespace std;

const int MAXN=400005;

vector<int> par(MAXN), sz(MAXN);

int find_set(int u){
    if(par[u]==u)return u;
    return par[u]=find_set(par[u]);
}

bool union_sets(int u,int v){
    u=find_set(u);
    v=find_set(v);
    if(u==v)return false;
    if(sz[u]<sz[v])swap(u,v);
    par[v]=u;
    sz[u]+=sz[v];
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,m,q;
    cin>>n>>m>>q;
    
    for(int i=1;i<=n*m;++i){
        par[i]=i;
        sz[i]=1;
    }
    
    while(q--){
        int x,y;
        cin>>x>>y;
        --x,--y;
        int id=x*m+y+1;
        
        int r=id/m,c=id%m+1;
        
        int dir[]={0,1,0,-1};
        for(int k=0;k<4;++k){
            int nr=r+dir[k],nc=c+dir[(k+1)%4];
            if(nr>=0&&nr<n&&nc>=0&&nc<m){
                int nid=nr*m+nc+1;
                if(find_set(id)!=find_set(nid)){
                    union_sets(id,nid);
                }
            }
        }
    }
    
    unordered_map<int,bool> vis;
    for(int i=1;i<=n*m;++i){
        int pid=find_set(i);
        if(vis.find(pid)==vis.end()){
            vis[pid]=true;
        }
    }
    
    cout<<n*m-vis.size()<<endl;
    
    return 0;
}