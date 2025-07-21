#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int MAXN=2e5+10;
vector<ll> vec[MAXN];
ll dist[MAXN];

int main(){
    ll n, m, u, v;
    scanf("%lld %lld", &n, &m);
    for(ll i = 1; i <= m; i++){
        scanf("%lld %lld", &u, &v);
        vec[u].push_back(v);
    }

    memset(dist, -1, sizeof(dist));
    queue<ll> q;
    
    // Initialize BFS from node 1's neighbors
    for(auto neighbor : vec[1]){
        if(neighbor == 1){
            printf("1");
            return 0;
        }
        dist[neighbor] = 1;
        q.push(neighbor);
    }

    while(!q.empty()){
        ll current = q.front();
        q.pop();
        
        for(auto next : vec[current]){
            if(next == 1){
                printf("%lld", dist[current] + 1);
                return 0;
            }
            if(dist[next] == -1){
                dist[next] = dist[current] + 1;
                q.push(next);
            }
        }
    }

    printf("-1");
    return 0;
}