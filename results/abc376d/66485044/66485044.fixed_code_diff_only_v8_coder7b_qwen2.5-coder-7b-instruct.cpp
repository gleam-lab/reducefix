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
    step[1] = 0; // Initialize the starting point's step as 0
    vis[1] = true; // Mark the starting point as visited
    while(!q.empty()){
        ll top=q.front();
        q.pop();
        for(ll i=0;i<vec[top].size();i++){
            ll to=vec[top][i];
            if(step[top] + 1 < step[to]){ // Update step only if a shorter path is found
                step[to] = step[top] + 1;
                vis[to] = true; // Mark the neighbor as visited
                q.push(to);
            }
        }
    }
    if(step[n] != INF) { // Check if the destination can be reached
        printf("%lld", step[n]);
    } else {
        printf("-1"); // If not reachable, print -1
    }
    return 0;
}