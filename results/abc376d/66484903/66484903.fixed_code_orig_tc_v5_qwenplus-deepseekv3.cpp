#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int MAXN=2e5+10;
vector<ll> vec[MAXN];
ll dist[MAXN];
ll parent[MAXN];
ll min_cycle = INF;

void bfs(ll start) {
    queue<ll> q;
    q.push(start);
    dist[start] = 0;
    
    while(!q.empty()) {
        ll u = q.front();
        q.pop();
        
        for(ll v : vec[u]) {
            if(v == start) {
                min_cycle = min(min_cycle, dist[u] + 1);
            }
            if(dist[v] == -1) {
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }
}

int main(){
    ll n,m,u,v;
    scanf("%lld %lld",&n,&m);
    for(ll i=1;i<=m;i++){
        scanf("%lld %lld",&u,&v);
        vec[u].push_back(v);
    }
    
    memset(dist, -1, sizeof(dist));
    memset(parent, -1, sizeof(parent));
    bfs(1);
    
    if(min_cycle != INF) {
        printf("%lld", min_cycle);
    } else {
        printf("-1");
    }
    return 0;
}