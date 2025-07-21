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
        // Check for self-loop at node 1
        if(u == 1 && v == 1){
            printf("1");
            return 0;
        }
    }

    fill(dist, dist + MAXN, INF);
    queue<ll> q;
    q.push(1);
    dist[1] = 0;

    while(!q.empty()){
        ll top = q.front();
        q.pop();
        for(ll neighbor : vec[top]){
            // Found a cycle back to node 1
            if(neighbor == 1 && dist[top] + 1 < INF){
                printf("%lld", dist[top] + 1);
                return 0;
            }
            // Relax the edge
            if(dist[neighbor] > dist[top] + 1){
                dist[neighbor] = dist[top] + 1;
                q.push(neighbor);
            }
        }
    }

    printf("-1");
    return 0;
}