#include<bits/stdc++.h>
using namespace std;

struct UnionFind{
    int n, group_cnt;
    vector<int> par;
    UnionFind(int n):n(n),group_cnt(n),par(n,-1){}
    int root(int x){
        return par[x]<0?x:par[x]=root(par[x]);
    }
    bool unite(int x,int y){
        x=root(x),y=root(y);
        if(x==y)return false;
        if(par[x]>par[y])swap(x,y);
        par[x]+=par[y];
        par[y]=x;
        group_cnt--;
        return true;
    }
    bool same(int x,int y){return root(x)==root(y);}
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int h,w,q;
    cin>>h>>w>>q;
    UnionFind u(h*w);
    vector<bool> vis(h*w,false);
    
    while(q--){
        int r,c;
        cin>>r>>c;
        r--,c--;

        if(vis[r*w+c]){
            for(int dr=-1;dr<=1;++dr){
                for(int dc=-1;dc<=1;++dc){
                    if(dr==0&&dc==0)continue;
                    if(r+dr>=0&&r+dr<h&&c+dc>=0&&c+dc<w&&!vis[(r+dr)*w+(c+dc)]){
                        u.unite(r*w+c,(r+dr)*w+(c+dc));
                    }
                }
            }
        }

        vis[r*w+c]=true;
    }

    unordered_set<int> groups;
    for(int i=0;i<h;++i){
        for(int j=0;j<w;++j){
            groups.insert(u.root(i*w+j));
        }
    }

    cout<<groups.size()<<endl;

    return 0;
}