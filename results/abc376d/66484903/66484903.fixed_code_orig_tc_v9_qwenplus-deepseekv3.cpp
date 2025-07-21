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
    
    ll min_cycle = INF;
    // Check for direct edge from node 1 to itself first
    for(auto to : vec[1]) {
        if(to == 1) {
            min_cycle = 1;
            break;
        }
    }
    if(min_cycle == 1) {
        printf("1");
        return 0;
    }

    // Perform BFS to find shortest path back to 1
    q.push(1);
    vis[1] = true;
    step[1] = 0;
    
    while(!q.empty()){
        ll top=q.front();
        q.pop();
        for(ll i=0;i<vec[top].size();i++){
            ll to=vec[top][i];
            if(!vis[to]){
                vis[to]=true;
                step[to]=step[top]+1;
                q.push(to);
            }
        }
    }
    
    // Check all nodes that have edges back to 1
    for(ll i=1;i<=n;i++){
        if(vis[i]){
            for(auto to : vec[i]){
                if(to == 1){
                    min_cycle = min(min_cycle, step[i]+1);
                }
            }
        }
    }
    
    if(min_cycle != INF) printf("%lld",min_cycle);
    else printf("-1");
    return 0;
}