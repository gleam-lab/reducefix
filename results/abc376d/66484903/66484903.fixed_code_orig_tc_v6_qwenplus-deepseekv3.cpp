#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int MAXN=2e5+10;
vector<ll> vec[MAXN];
queue<ll> q;
ll dist[MAXN];
bool vis[MAXN];

int main(){
    ll n,m,u,v;
    scanf("%lld %lld",&n,&m);
    for(ll i=1;i<=m;i++){
        scanf("%lld %lld",&u,&v);
        vec[u].push_back(v);
    }
    
    // Initialize distances to infinity
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    q.push(1);
    
    while(!q.empty()){
        ll top=q.front();
        q.pop();
        for(auto to : vec[top]){
            if(to == 1){
                printf("%lld", dist[top] + 1);
                return 0;
            }
            if(dist[to] > dist[top] + 1){
                dist[to] = dist[top] + 1;
                q.push(to);
            }
        }
    }
    printf("-1");
    return 0;
}