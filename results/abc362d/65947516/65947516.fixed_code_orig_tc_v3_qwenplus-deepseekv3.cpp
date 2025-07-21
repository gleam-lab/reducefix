#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<climits> 
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pii;
const int N=2e5+5;

int n,m;
ll a[N];
ll dis[N];
bool vis[N];
vector<pii> g[N];

void heap_dijkstra() {
    memset(vis,false,sizeof(vis));
    for(int i=1;i<=n;i++)
        dis[i]=LONG_LONG_MAX;
    
    priority_queue<pii, vector<pii>, greater<pii>> q;
    dis[1] = a[1];
    q.push({dis[1], 1});
    
    while(!q.empty()) {
        pii now = q.top();
        q.pop();
        int u = now.second;
        if(vis[u]) continue;
        vis[u] = true;
        
        for(pii edge : g[u]) {
            int v = edge.second;
            ll w = edge.first + a[v];
            if(dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                q.push({dis[v], v});
            }
        }
    }
}

int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    for(int i=1;i<=m;i++) {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        g[u].push_back({w, v});
        g[v].push_back({w, u});
    }
    
    heap_dijkstra();
    
    for(int i=2;i<=n;i++) {
        printf("%lld ", dis[i]);
    }
    return 0;
}