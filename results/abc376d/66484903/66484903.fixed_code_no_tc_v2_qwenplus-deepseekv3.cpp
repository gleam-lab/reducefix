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
    ll ans = INF;
    
    while(!q.empty()){
        ll top = q.front();
        q.pop();
        
        for(ll to : vec[top]){
            if(to == 1){
                ans = min(ans, dist[top] + 1);
                continue;
            }
            if(dist[to] == -1){
                dist[to] = dist[top] + 1;
                q.push(to);
            }
        }
    }
    
    printf("%lld", ans == INF ? -1 : ans);
    return 0;
}