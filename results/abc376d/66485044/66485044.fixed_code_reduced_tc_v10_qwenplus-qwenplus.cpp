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

    // Initialize BFS from node 1
    memset(step, INF, sizeof(step));
    step[1] = 0;
    vis[1] = true;
    q.push(1);

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

    // Look for the shortest cycle involving node 1
    ll min_cycle = INF;
    for(ll i=1; i<=n; ++i){
        if(vec[i].size() > 0 && i != 1 && step[i] != INF && step[i] != 0){
            for(ll neighbor : vec[i]){
                if(neighbor == 1){
                    min_cycle = min(min_cycle, step[i] + 1);
                }
            }
        }
    }

    if(min_cycle != INF)
        printf("%lld\n", min_cycle);
    else
        printf("-1\n");

    return 0;
}