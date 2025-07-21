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
    memset(vis,false,sizeof(vis));
    for(ll i=1;i<=m;i++){
        scanf("%lld %lld",&u,&v);
        vec[u].push_back(v);
    }
    q.push(1);
    step[1] = 0; // Initialize the starting node's step count to 0
    while(!q.empty()){
        ll top=q.front();
        q.pop();
        for(ll i=0;i<vec[top].size();i++){
            ll to=vec[top][i];
            if(to==n){ // Change the condition to check against 'n' instead of '1'
                printf("%lld\n",step[top]+1); // Print the number of steps + 1 (since we start counting from 0)
                return 0;
            }
            if(!vis[to]){
                step[to]=step[top]+1;
                vis[to]=true; // Mark the node as visited after processing its neighbors
                q.push(to);
            }
        }
    }
    printf("-1");
    return 0;
}