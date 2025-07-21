#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=2e5+10;
const ll INF=0x3f3f3f3f3f3f3f3f;

vector<ll> graph[MAXN];
ll dist[MAXN];

int main(){
    ll n, m, u, v;
    scanf("%lld %lld",&n,&m);
    for(ll i=0;i<m;i++){
        scanf("%lld %lld",&u,&v);
        graph[u].push_back(v);
    }
    
    fill(dist, dist+n+1, INF);
    queue<ll> q;
    
    // Start BFS from node 1's neighbors
    for(auto neighbor : graph[1]){
        if(neighbor == 1){
            // Direct self-loop case
            printf("1");
            return 0;
        }
        dist[neighbor] = 1;
        q.push(neighbor);
    }
    
    while(!q.empty()){
        ll current = q.front();
        q.pop();
        
        for(auto next : graph[current]){
            if(next == 1){
                // Found a path back to node 1
                printf("%lld", dist[current] + 1);
                return 0;
            }
            if(dist[next] == INF){
                dist[next] = dist[current] + 1;
                q.push(next);
            }
        }
    }
    
    printf("-1");
    return 0;
}