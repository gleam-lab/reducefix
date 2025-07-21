#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int MAXN=2e5+10;
vector<ll> vec[MAXN];
queue<ll> q;
ll step[MAXN];
bool inQueue[MAXN];

int main(){
    ll n, m, u, v;
    scanf("%lld %lld", &n, &m);
    for(ll i=1; i<=m; i++){
        scanf("%lld %lld", &u, &v);
        vec[u].push_back(v);
    }
    
    memset(step, INF, sizeof(step));
    step[1] = 0;
    q.push(1);
    inQueue[1] = true;
    
    while(!q.empty()){
        ll top = q.front();
        q.pop();
        inQueue[top] = false;
        
        for(ll i=0; i<vec[top].size(); i++){
            ll to = vec[top][i];
            if(to == 1){
                if(step[top] + 1 < step[to]){
                    step[to] = step[top] + 1;
                    printf("%lld", step[to]);
                    return 0;
                }
            }
            if(step[top] + 1 < step[to]){
                step[to] = step[top] + 1;
                if(!inQueue[to]){
                    q.push(to);
                    inQueue[to] = true;
                }
            }
        }
    }
    
    printf("-1");
    return 0;
}