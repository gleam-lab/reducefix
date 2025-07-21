#include<bits/stdc++.h>
using namespace std;
#define int long long 
vector<pair<int,pair<int, int>>>G[200005]; // Store edge with {weight, vertex}
int dis[200005],a[200005],n,m,vis[200005];
void dij(int u){
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>q;
	q.push({0, {a[u], u}}); // Push the initial vertex with its vertex value, vertex
	while(!q.empty()){
		int d = q.top().first;
		int u = q.top().second.second;
		int av = q.top().second.first;
		q.pop();
		if(vis[u] && av == a[u]) continue; // Ignore revisits with the same accumulated vertex weight
		vis[u] = 1;
		for(auto [v, w] : G[u]){
			if(!vis[v]){
				q.push({d + w, {a[v], v}}); // Push new vertex with updated accumulated distance
				dis[v] = d + w + av; // Update distance considering the vertex weight
			}
		}
	}
}

signed main() {
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}
	memset(dis, 0x3f, sizeof dis);
	dij(1); // Perform Dijkstra's algorithm starting from vertex 1
	for(int i=2;i<=n;i++){
		cout<<dis[i]<<' ';
	}
	cout<<"\n";
	return 0;
}