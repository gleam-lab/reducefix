#include<bits/stdc++.h>

using namespace std;

const int MAXN=400010;

vector<int> par(MAXN,-1);

int find(int x){
    if(par[x]==-1)return x;
    else return par[x]=find(par[x]);
}

void unite(int x,int y){
    int px=find(x),py=find(y);
    if(px==py)return ;
    par[px]=py;
}

int main(){
    int n,m,q,i,j,k,l,x,y;
    scanf("%d%d%d",&n,&m,&q);
    for(i=1;i<=n*m;++i)par[i]=i;
    while(q--){
        scanf("%d%d",&x,&y);
        x--,y--;
        int u=x*m+y+1,v=(x+1)*m+y+1,w=x*m+(y+1)+1,t=(x+1)*m+(y+1)+1;
        if(u!=v)unite(u,v);
        if(u!=w)unite(u,w);
        if(v!=t)unite(v,t);
        if(w!=t)unite(w,t);
    }
    unordered_set<int> s;
    for(i=1;i<=n*m;++i)s.insert(find(i));
    printf("%zu\n",s.size());
    return 0;
}