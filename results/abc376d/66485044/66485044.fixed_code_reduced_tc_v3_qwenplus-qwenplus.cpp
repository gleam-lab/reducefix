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
    for(ll i=1;i<=n;i++) step[i] = INF;
    
    for(ll i=1;i<=m;i++){
        scanf("%lld %lld",&u,&v);
        vec[u].push_back(v);
    }

    // BFS from node 1
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

    // Look for a cycle back to 1 (excluding the starting point itself)
    ll min_cycle_length = INF;
    for(ll i=1; i<=n; ++i) {
        for(ll neighbor : vec[i]) {
            if(neighbor == 1 && step[i] != INF) {
                min_cycle_length = min(min_cycle_length, step[i] + 1LL);
            }
        }
    }

    if(min_cycle_length != INF)
        printf("%lld\n", min_cycle_length);
    else
        printf("-1\n");

    return 0;
}