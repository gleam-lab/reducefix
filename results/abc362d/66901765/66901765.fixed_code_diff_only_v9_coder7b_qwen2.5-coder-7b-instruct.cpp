#include<bits/stdc++.h>
using namespace std;
#define int long long 
vector<pair<int,int>>G[200005];
int dis[200005],dis2[200005],a[200005],n,m,vis[200005];
void dij(int u){
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
	q.push({0,u});
	while(!q.empty()){
		int u=q.top().second;
		int d=q.top().first;
		q.pop();
		if(vis[u]) continue; // Skip already visited nodes
		vis[u] = 1;
		for(auto [v,w]:G[u]){
			if(dis[v] > d + a[v] + w){
				dis[v] = d + a[v] + w;
				q.push({dis[v],v});
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
	memset(dis,0x3f3f3f3f,sizeof dis); // Initialize distance array properly
	dis[1]=a[1]; // Correct initial distance for source node
	dij(1);
	for(int i=2;i<=n;i++){
		printf("%lld ",dis[i]); // Print results without trailing space
	}
	return 0;
}