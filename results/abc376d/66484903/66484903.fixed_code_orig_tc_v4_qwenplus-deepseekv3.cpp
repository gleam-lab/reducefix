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
    
    memset(step, -1, sizeof(step));
    step[1] = 0;
    q.push(1);
    
    ll min_cycle = INF;
    
    while(!q.empty()){
        ll top=q.front();
        q.pop();
        
        for(ll i=0;i<vec[top].size();i++){
            ll to=vec[top][i];
            if(to == 1){
                min_cycle = min(min_cycle, step[top] + 1);
                continue;
            }
            if(step[to] == -1){
                step[to] = step[top] + 1;
                q.push(to);
            }
        }
    }
    
    if(min_cycle != INF)
        printf("%lld", min_cycle);
    else
        printf("-1");
    return 0;
}