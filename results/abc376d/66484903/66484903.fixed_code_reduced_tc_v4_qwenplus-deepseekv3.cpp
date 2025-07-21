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
    q.push(1);
    vis[1] = true;
    step[1] = 0;
    while(!q.empty()){
        ll top=q.front();
        q.pop();
        for(ll i=0;i<vec[top].size();i++){
            ll to=vec[top][i];
            if(to == 1){
                printf("%lld", step[top] + 1);
                return 0;
            }
            if(!vis[to]){
                vis[to] = true;
                step[to] = step[top] + 1;
                q.push(to);
            }
        }
    }
    printf("-1");
    return 0;
}