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
    
    // Check for immediate self-loop (1->1)
    for(auto to : vec[1]) {
        if(to == 1) {
            printf("1\n");
            return 0;
        }
    }
    
    memset(dist, -1, sizeof(dist));
    queue<ll> q;
    q.push(1);
    dist[1] = 0;
    ll res = INF;
    
    while(!q.empty()){
        ll u = q.front();
        q.pop();
        
        for(auto v : vec[u]){
            if(v == 1){
                res = min(res, dist[u] + 1);
                continue;
            }
            if(dist[v] == -1){
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    
    printf("%lld\n", res == INF ? -1 : res);
    return 0;
}