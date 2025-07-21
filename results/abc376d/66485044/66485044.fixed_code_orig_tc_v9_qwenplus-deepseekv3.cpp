#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int MAXN=2e5+10;
vector<ll> vec[MAXN];
ll dist[MAXN];

int main(){
    ll n,m,u,v;
    scanf("%lld %lld",&n,&m);
    for(ll i=1;i<=m;i++){
        scanf("%lld %lld",&u,&v);
        vec[u].push_back(v);
    }
    
    fill(dist, dist+MAXN, INF);
    dist[1] = 0;
    
    queue<ll> q;
    q.push(1);
    
    ll res = INF;
    
    while(!q.empty()){
        ll u = q.front();
        q.pop();
        
        for(ll v : vec[u]){
            if(v == 1){
                res = min(res, dist[u] + 1);
            }
            if(dist[v] > dist[u] + 1){
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    
    if(res == INF) printf("-1\n");
    else printf("%lld\n", res);
    
    return 0;
}