#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int MAXN=2e5+10;
vector<ll> vec[MAXN];
queue<ll> q;
ll step[MAXN];
bool vis[MAXN];
int main(){
    ll n,m,u,v;
    scanf("%lld %lld",&n,&m);
    for(ll i=1;i<=m;i++){
        scanf("%lld %lld",&u,&v);
        vec[u].push_back(v);
    }
    
    // Initialize step and vis arrays
    memset(step, INF, sizeof(step));
    memset(vis, false, sizeof(vis));
    
    // Start from node 1
    q.push(1);
    step[1] = 0;
    vis[1] = true;
    
    while(!q.empty()){
        ll top = q.front();
        q.pop();
        
        for(ll to : vec[top]){
            if(step[to] > step[top] + 1){
                step[to] = step[top] + 1;
                q.push(to);
            }
        }
    }
    
    if(step[n] == INF) {
        printf("-1");
    } else {
        printf("%lld", step[n]);
    }
    
    return 0;
}