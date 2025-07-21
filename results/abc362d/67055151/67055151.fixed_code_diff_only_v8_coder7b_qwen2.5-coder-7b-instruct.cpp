#include <bits/stdc++.h>

using namespace std;

#define forn(i,n) for(int i=0;i<n;i++)
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAXN = 2e5+7;

int n,m,a[MAXN],par[MAXN],rank[MAXN];
vector<pii> adj[MAXN];

void init(){
    forn(i,n){
        par[i]=i;
        rank[i]=0;
    }
}

int find(int u){
    if(par[u]==u)return u;
    return par[u]=find(par[u]);
}

void merge(int u,int v){
    u=find(u);
    v=find(v);
    if(rank[u]>rank[v]){
        par[v]=u;
    }else{
        par[u]=v;
        if(rank[u]==rank[v])rank[v]++;
    }
}

ll dijkstra(int src){
    vector<ll> dist(n,LLONG_MAX);
    dist[src]=0;
    set<pii> st;
    st.insert({dist[src],src});
    while(!st.empty()){
        auto [d,u]=*st.begin();
        st.erase(st.begin());
        if(d!=dist[u])continue;
        for(auto [v,w]:adj[u]){
            if(dist[u]+w<dist[v]){
                st.erase({dist[v],v});
                dist[v]=dist[u]+w;
                st.insert({dist[v],v});
            }
        }
    }
    return dist[n-1];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>n>>m;
    forn(i,n)cin>>a[i];
    forn(i,m){
        int u,v,w;
        cin>>u>>v>>w;
        u--,v--;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }
    
    init();
    forn(i,n){
        merge(i,i+1);
    }
    
    ll ans[n-1];
    forn(i,n-1){
        int u=i+1,v=i+2;
        int pu=find(u),pv=find(v);
        if(pu==pv){
            ans[i]=dijkstra(i);
        }else{
            ans[i]=a[u]+a[v];
        }
    }
    
    forn(i,n-1)cout<<ans[i]<<" ";
    cout<<endl;
    
    return 0;
}