#include<bits/stdc++.h>
using namespace std;
#define int long long 
vector<pair<int,int>>G[200005];
int dis[200005],a[200005],n,m;

void dij(int s){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,s});
    while(!pq.empty()){
        int u = pq.top().second;
        int dist_u = pq.top().first;
        pq.pop();
        if(dist_u > dis[u]) continue; // Skip outdated entries in the priority queue
        
        for(auto [v,w] : G[u]){
            int new_dist = dist_u + a[v] + w;
            if(new_dist < dis[v]){
                dis[v] = new_dist;
                pq.push({new_dist,v});
            }
        }
    }
}

signed main() {
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    for(int i=1;i<=m;i++){
        int u,v,w;
        scanf("%lld%lld%lld",&u,&v,&w);
        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }
    memset(dis,0x3f,sizeof dis);
    dis[1] = a[1]; // Initialize distance to starting node
    dij(1); // Run Dijkstra's algorithm starting from node 1
    for(int i=2;i<=n;i++){
        cout << dis[i] << ' '; // Print results for nodes 2 through n
    }
    cout << "\n";
    return 0;
}