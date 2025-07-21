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
    step[1] = 0; // Initialize step for node 1
    vis[1] = true;
    while(!q.empty()){
        ll top=q.front();
        q.pop();
        for(ll i=0;i<vec[top].size();i++){
            ll to=vec[top][i];
            if(step[to] == -1 || step[to] > step[top] + 1) { // Check if it's not visited or a shorter path is found
                step[to] = step[top] + 1;
                vis[to] = true;
                q.push(to);
                if(to == 1 && top != 1){ // If target node 1 is reached and it's not the starting node
                    printf("%lld\n", step[top]);
                    return 0;
                }
            }
        }
    }
    printf("-1\n"); // If node 1 is not reachable from any other node except itself
    return 0;
}