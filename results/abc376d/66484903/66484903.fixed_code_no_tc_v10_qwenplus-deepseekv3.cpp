#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int MAXN=2e5+10;
vector<ll> vec[MAXN];
ll step[MAXN];

int main(){
    ll n,m,u,v;
    scanf("%lld %lld",&n,&m);
    for(ll i=1;i<=m;i++){
        scanf("%lld %lld",&u,&v);
        vec[u].push_back(v);
    }
    
    queue<ll> q;
    fill(step, step+MAXN, INF);
    step[1] = 0;
    q.push(1);
    
    ll min_cycle = INF;
    
    while(!q.empty()){
        ll top = q.front();
        q.pop();
        
        for(ll to : vec[top]){
            if(to == 1){
                min_cycle = min(min_cycle, step[top] + 1);
            }
            if(step[to] > step[top] + 1){
                step[to] = step[top] + 1;
                q.push(to);
            }
        }
    }
    
    printf("%lld", (min_cycle == INF) ? -1 : min_cycle);
    return 0;
}