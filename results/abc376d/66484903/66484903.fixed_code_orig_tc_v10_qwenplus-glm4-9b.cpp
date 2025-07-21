#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int MAXN=2e5+10;
vector<ll> vec[MAXN];
vector<ll> parent[MAXN];
bool vis[MAXN];
vector<pair<ll,ll>> path;
ll step[MAXN];
int main(){
    ll n,m,u,v;
    scanf("%lld %lld",&n,&m);
    for(ll i=1;i<=m;i++){
        scanf("%lld %lld",&u,&v);
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    q.push(1);
    step[1]=0;
    while(!q.empty()){
        ll top=q.front();
        vis[top]=true;
        q.pop();
        for(ll i=0;i<vec[top].size();i++){
            ll to=vec[top][i];
            if(!vis[to]){
                parent[to]=top;
                step[to]=step[top]+1;
                q.push(to);
            }
        }
    }
    if(step[1]==INF){
        printf("-1");
    } else {
        ll current=1;
        while(current!=1){
            path.push_back({current,step[current]});
            current=parent[current];
        }
        path.push_back({1,step[1]});
        reverse(path.begin(),path.end());
        for(auto p : path){
            printf("%lld ",p.first);
        }
    }
    return 0;
}