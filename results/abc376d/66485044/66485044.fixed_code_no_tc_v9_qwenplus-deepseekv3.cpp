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
    
    // Initialize step with -1 (unvisited)
    memset(step, -1, sizeof(step));
    q.push(1);
    step[1] = 0;
    vis[1] = true;
    
    while(!q.empty()){
        ll top = q.front();
        q.pop();
        
        for(ll neighbor : vec[top]){
            if(neighbor == 1 && step[top] + 1 > 0){
                // Found a cycle back to 1
                printf("%lld", step[top] + 1);
                return 0;
            }
            if(!vis[neighbor]){
                vis[neighbor] = true;
                step[neighbor] = step[top] + 1;
                q.push(neighbor);
            }
        }
    }
    
    // No cycle found
    printf("-1");
    return 0;
}