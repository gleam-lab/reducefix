#include<bits/stdc++.h>
using namespace std;

const int MAXN=2e5+7;

struct UnionFind{
    int parent[MAXN],rank[MAXN];
    UnionFind(){
        memset(parent,-1,sizeof(parent));
        memset(rank,0,sizeof(rank));
    }
    int findSet(int u){
        return parent[u]==u?u:(parent[u]=findSet(parent[u]));
    }
    void unionSets(int u,int v){
        u=findSet(u);
        v=findSet(v);
        if(u!=v){
            if(rank[u]>rank[v]){
                parent[v]=u;
            }
            else{
                parent[u]=v;
                if(rank[u]==rank[v]) rank[v]++;
            }
        }
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,q;
    cin>>n>>m>>q;

    UnionFind UF;

    vector<vector<int>> grid(n,vector<int>(m));

    while(q--){
        int x,y;
        cin>>x>>y;
        x--,y--;

        if(grid[x][y]==1){
            grid[x][y]=0;
        }
        else{
            for(int i=x;i>=0;i--){
                if(grid[i][y]==1){
                    UF.unionSets(i*m+y,(i-1)*m+y);
                    break;
                }
            }

            for(int i=x;i<n;i++){
                if(grid[i][y]==1){
                    UF.unionSets(i*m+y,(i+1)*m+y);
                    break;
                }
            }

            for(int j=y;j>=0;j--){
                if(grid[x][j]==1){
                    UF.unionSets(x*m+j,x*m+(j-1));
                    break;
                }
            }

            for(int j=y;j<m;j++){
                if(grid[x][j]==1){
                    UF.unionSets(x*m+j,x*m+(j+1));
                    break;
                }
            }
        }
    }

    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==0){
                ans++;
            }
        }
    }

    cout<<ans<<endl;

    return 0;
}