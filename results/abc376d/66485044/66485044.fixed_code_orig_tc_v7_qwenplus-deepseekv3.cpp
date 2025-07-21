#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int MAXN=2e5+10;
vector<ll> vec[MAXN];
ll step[MAXN];
bool vis[MAXN];

int main(){
    ll n,m,u,v;
    scanf("%lld %lld",&n,&m);
    for(ll i=1;i<=m;i++){
        scanf("%lld %lld",&u,&v);
        vec[u].push_back(v);
    }
    
    ll min_cycle = INF;
    
    // Special case: check if node 1 has a direct connection to itself
    for(auto to : vec[1]) {
        if(to == 1) {
            min_cycle = 1;
            break;
        }
    }
    if(min_cycle == 1) {
        printf("1\n");
        return 0;
    }
    
    // BFS to find shortest cycle through node 1
    queue<ll> q;
    q.push(1);
    step[1] = 0;
    vis[1] = true;
    
    while(!q.empty() && min_cycle > 3) {
        ll top = q.front();
        q.pop();
        
        for(auto to : vec[top]) {
            if(to == 1 && top != 1) {
                min_cycle = min(min_cycle, step[top] + 1);
                continue;
            }
            if(vis[to]) continue;
            
            vis[to] = true;
            step[to] = step[top] + 1;
            q.push(to);
        }
    }
    
    if(min_cycle == INF) {
        printf("-1\n");
    } else {
        printf("%lld\n", min_cycle);
    }
    return 0;
}