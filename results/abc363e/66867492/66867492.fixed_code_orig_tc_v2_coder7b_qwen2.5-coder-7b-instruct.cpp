#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define pob pop_back
#define el '\n'
#define YES cout<<"Yes"<<el
#define NO cout<<"No"<<el
#define NG cout<<-1<<el
#define ansNG(ans,ng) if(ans==ng){ NG; }else{ cout<<ans<<el; }
#define all(a)  a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define rep(i,n)     for(int i = 0; i < (n); ++i)
#define rep3(i,l,r)  for(int i = (l); i < (r); ++i)
#define rrep(i,n)    for(int i = (n)-1; i >= 0; --i)
#define rrep3(i,l,r) for(int i = (r)-1; i >= (l); --i)
#define next_p(x) next_permutation( x )
#define INF    1e9+10
#define INFi64 (i64)2e18+10
#define m 998244353; //m=1e9+7;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

vector<vector<int>> adj(1005,vector<int>());
vector<bool> vis(1005,false);
vector<int> lvl(1005), par(1005);

void bfs(int src,int n){
    queue<int> q;
    q.push(src);
    vis[src]=true;
    lvl[src]=0;
    par[src]=-1;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(auto v:adj[u]){
            if(!vis[v]){
                vis[v]=true;
                lvl[v]=lvl[u]+1;
                par[v]=u;
                q.push(v);
            }
        }
    }
}

int find(int a){
    if(par[a]==a)return a;
    return par[a]=find(par[a]);
}

bool Union(int a,int b){
    int pa=find(a),pb=find(b);
    if(pa==pb)return false;
    if(lvl[pa]<lvl[pb])swap(pa,pb);
    par[pb]=pa;
    lvl[pa]+=lvl[pb];
    return true;
}

int main(){
    int h,w,y;cin>>h>>w>>y;
    vector<vector<int>> grid(h,vector<int>(w));
    for(int i=0;i<h;++i){
        for(int j=0;j<w;++j){
            cin>>grid[i][j];
        }
    }
    
    vector<pair<int,pair<int,int>>> edges;
    for(int i=0;i<h;++i){
        for(int j=0;j<w;++j){
            if(i+1<h)edges.emplace_back(grid[i][j],make_pair(i,j));
            if(j+1<w)edges.emplace_back(grid[i][j],make_pair(i,j));
        }
    }
    sort(all(edges));
    
    vector<vector<int>> parent(h,vector<int>(w,-1));
    vector<vector<int>> rank(h,vector<int>(w,0));
    
    function<bool(int,int)> valid=[&](int x,int y){
        return x>=0&&x<h&&y>=0&&y<w;
    };
    
    auto merge=[&](int x,int y){
        int px=find(parent[x][y]),py=find(parent[x][y]);
        if(px!=py){
            if(rank[px]>rank[py])parent[py][x][y]=px;
            else{
                parent[px][x][y]=py;
                if(rank[px]==rank[py])rank[py]++;
            }
        }
    };
    
    vector<int> areas(y+1,0);
    for(int k=0;k<edges.size();++k){
        int cost=edges[k].first;
        int x=edges[k].second.first,y=edges[k].second.second;
        
        if(valid(x-1,y)&&parent[x-1][y]!=-1){
            merge(x-1,y,x,y);
        }
        if(valid(x+1,y)&&parent[x+1][y]!=-1){
            merge(x+1,y,x,y);
        }
        if(valid(x,y-1)&&parent[x][y-1]!=-1){
            merge(x,y-1,x,y);
        }
        if(valid(x,y+1)&&parent[x][y+1]!=-1){
            merge(x,y+1,x,y);
        }
        
        int root=find(parent[x][y]);
        if(root==-1)continue;
        areas[cost]++;
    }
    
    for(int i=y;i>0;--i){
        areas[i-1]+=areas[i];
    }
    
    for(int i=0;i<y;++i){
        cout<<areas[i]<<el;
    }
    
    return 0;
}