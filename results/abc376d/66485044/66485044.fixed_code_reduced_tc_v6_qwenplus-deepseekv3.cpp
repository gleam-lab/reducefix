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
    ll n, m, u, v;
    scanf("%lld %lld", &n, &m);
    for(ll i=1; i<=m; i++){
        scanf("%lld %lld", &u, &v);
        vec[u].push_back(v);
        // Check if there's a direct self-loop from 1 to 1
        if(u == 1 && v == 1){
            printf("1\n");
            return 0;
        }
    }
    fill(step, step + MAXN, INF);
    step[1] = 0;
    q.push(1);
    vis[1] = true;
    while(!q.empty()){
        ll top = q.front();
        q.pop();
        for(ll i=0; i<vec[top].size(); i++){
            ll to = vec[top][i];
            if(to == 1 && top != 1){
                printf("%lld\n", step[top] + 1);
                return 0;
            }
            if(!vis[to]){
                vis[to] = true;
                step[to] = step[top] + 1;
                q.push(to);
            }
        }
    }
    printf("-1\n");
    return 0;
}