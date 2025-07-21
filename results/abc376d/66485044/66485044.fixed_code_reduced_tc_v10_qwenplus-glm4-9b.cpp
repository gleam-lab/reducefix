#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int MAXN=2e5+10;
vector<ll> vec[MAXN];
queue<ll> q;
ll dist[MAXN];
bool vis[MAXN];

int main(){
    ll n, m;
    scanf("%lld %lld", &n, &m);
    for(ll i = 0; i < m; i++){
        ll u, v;
        scanf("%lld %lld", &u, &v);
        vec[u].push_back(v);
        vec[v].push_back(u); // Ensure bidirectional graph
    }
    q.push(1);
    dist[1] = 0; // Start from node 1
    vis[1] = true;
    while(!q.empty()){
        ll top = q.front();
        q.pop();
        for(ll to : vec[top]){
            if(to == 1 && top != 1){
                printf("%lld\n", dist[top] + 1);
                return 0;
            }
            if(!vis[to] && dist[to] == -1){ // Only process if unvisited and not visited before by another path
                dist[to] = dist[top] + 1;
                q.push(to);
                vis[to] = true;
            }
        }
    }
    printf("-1\n");
    return 0;
}