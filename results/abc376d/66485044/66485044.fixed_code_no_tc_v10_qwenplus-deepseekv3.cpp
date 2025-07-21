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
    
    memset(dist, -1, sizeof(dist));
    queue<ll> q;
    q.push(1);
    dist[1] = 0;
    ll res = INF;
    
    while(!q.empty()){
        ll u = q.front();
        q.pop();
        
        for(ll v : vec[u]){
            if(v == 1){
                res = min(res, dist[u] + 1);
            }
            if(dist[v] == -1){
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    
    if(res != INF){
        printf("%lld", res);
    } else {
        printf("-1");
    }
    return 0;
}