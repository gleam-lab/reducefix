#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int MAXN=2e5+10;
vector<ll> vec[MAXN];
ll dist[MAXN];
ll rev_dist[MAXN];

void bfs(ll start, ll n, ll d[]) {
    for(ll i=1; i<=n; i++) d[i] = INF;
    queue<ll> q;
    q.push(start);
    d[start] = 0;
    while(!q.empty()) {
        ll u = q.front();
        q.pop();
        for(ll v : vec[u]) {
            if(d[v] == INF) {
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
}

int main(){
    ll n, m, u, v;
    scanf("%lld %lld", &n, &m);
    for(ll i=1; i<=m; i++) {
        scanf("%lld %lld", &u, &v);
        vec[u].push_back(v);
    }
    
    bfs(1, n, dist);
    
    // Now build reverse graph for distance from all nodes to 1
    vector<ll> rev_vec[MAXN];
    for(u=1; u<=n; u++) {
        for(v : vec[u]) {
            rev_vec[v].push_back(u);
        }
    }
    
    bfs(1, n, rev_dist); // This will give distances from nodes to 1 in original graph
    
    ll min_cycle = INF;
    for(u=1; u<=n; u++) {
        for(v : vec[u]) {
            if(rev_dist[v] != INF && u != v) { // Check if there's a path from v to 1
                min_cycle = min(min_cycle, dist[u] + 1 + rev_dist[v]);
            }
        }
    }
    
    if(min_cycle == INF) printf("-1\n");
    else printf("%lld\n", min_cycle);
    
    return 0;
}