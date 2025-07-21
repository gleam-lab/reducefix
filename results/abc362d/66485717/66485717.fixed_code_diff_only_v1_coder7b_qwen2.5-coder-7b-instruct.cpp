#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define INF 1e18
#define rep(i,a,b) for(int i=a;i<(b);i++)
#define trav(a,x) for(auto&a:x)
#define all(x) begin(x),end(x)

typedef pair<int,int> pii;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;

    vector<LL> a(n+1);
    rep(i,1,n+1)cin>>a[i];

    vector<vector<pii>> g(n+1);
    rep(i,0,m){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].pb(pii(v,w));
        g[v].pb(pii(u,w));
    }

    vector<LL> dist(n+1,INF);
    priority_queue<pair<LL,int>,vector<pair<LL,int>>,greater<pair<LL,int>>> pq;
    
    dist[1]=a[1];
    pq.push({dist[1],1});

    while(!pq.empty()){
        auto [d,u]=pq.top(); pq.pop();

        if(d!=dist[u])continue;

        trav(v,g[u]){
            int nxt=v.first, cost=v.second;
            LL nd=d+a[nxt]+cost;

            if(nd<dist[nxt]){
                dist[nxt]=nd;
                pq.push({nd,nxt});
            }
        }
    }

    rep(i,2,n+1)cout<<dist[i]<<" ";
    cout<<endl;

    return 0;
}