#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<climits> 
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pli;
const int N=2e5+5;
int n,m;
ll a[N];
ll dis[N];
vector<pli>g[N];

void dijkstra() {
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    for(int i=1;i<=n;i++) dis[i]=LLONG_MAX;
    dis[1]=a[1];
    pq.push({dis[1],1});
    while(!pq.empty()) {
        ll d=pq.top().first;
        int u=pq.top().second;
        pq.pop();
        if(d>dis[u]) continue;
        for(auto &[v,w]:g[u]) {
            if(dis[v]>dis[u]+w+a[v]) {
                dis[v]=dis[u]+w+a[v];
                pq.push({dis[v],v});
            }
        }
    }
}

int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(int i=1;i<=m;i++) {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        g[u].emplace_back(v,w);
        g[v].emplace_back(u,w);
    }
    dijkstra();
    for(int i=2;i<=n;i++) printf("%lld ",dis[i]);
    return 0;
}