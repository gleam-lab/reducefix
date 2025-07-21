#include "bits/stdc++.h"
using namespace std;
#define ff first
#define ss second
#define ll long long
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
const int N=2e5+5;
class DSU{
public:
    vector<int> parent,size;
    DSU(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++)
            parent[i]=i;
    }
    int findparent(int node){
        if(node==parent[node])
            return node;
        return parent[node]=findparent(parent[node]);
    }
    void unionbyrank(int u,int v){
        u=findparent(u);
        v=findparent(v);
        if(size[u]<size[v]){
            swap(u,v);
        }
        parent[v]=u;
        size[u]+=size[v];
    }
};
struct Edge{
    int u,v,w;
    bool operator<(Edge &o){
        return w<o.w;
    }
};
int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    DSU dsu(n);
    vector<Edge> edges(m);
    for(int i=0;i<m;i++){
        cin>>edges[i].u>>edges[i].v;
        edges[i].w=i+1;
    }
    sort(all(edges));
    priority_queue<pair<int,pair<int,int>>> pq;
    for(auto it:edges){
        int u=it.u,v=it.v;
        if(dsu.findparent(u)!=dsu.findparent(v)){
            dsu.unionbyrank(u,v);
            pq.push({it.w,{u,v}});
        }
    }
    vector<int> ans(m,-1);
    int cnt=0;
    while(!pq.empty()){
        auto it=pq.top();
        pq.pop();
        int w=it.first,u=it.second.ff,v=it.second.ss;
        if(cnt==n-1)
            break;
        ans[w]=cnt+1;
        cnt++;
    }
    for(int i=0;i<m;i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}