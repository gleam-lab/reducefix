#include<bits/stdc++.h>
using namespace std;
#define int long long 
vector<pair<int,int>>G[200005];
int dis[200005],dis2[200005],a[200005],n,m,vis[200005];
void dij(int u){
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q; // Change priority queue type to store smallest distance first
	q.push({0,u});
	while(!q.empty()){
		int u=q.top().second;
		int d=q.top().first; // Get current distance
		q.pop();
		if(d > dis[u]) continue; // Skip if already found a shorter path to this node
		if(vis[u]) continue; // Skip if already visited
		vis[u] = 1;
		for(auto [v,w]: G[u]){
			if(dis[v] > dis[u] + w + a[v]){ // Update distance if a shorter path is found
				dis[v] = dis[u] + w + a[v];
				q.push({dis[v], v}); // Push updated distance to priority queue
			}
		}
	}
}

signed main() {
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]); // Read vertex weights
	}
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w); // Read edge details
		G[u].push_back({v,w});
		G[v].push_back({u,w});
	}
	memset(dis,0x3f,sizeof dis); // Initialize distances to infinity
	dis[1] = a[1]; // Distance to starting node is its own weight
	dij(1); // Run Dijkstra's algorithm from the starting node
	for(int i=2;i<=n;i++){
		cout<<dis[i]<<' '; // Print minimum distances to other nodes
	}
	cout<<"\n";
	return 0;
}