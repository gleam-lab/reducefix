#include<bits/stdc++.h>
using namespace std;
#define int long long 
vector<pair<int,int>>G[200005];
int dis[200005],a[200005],n,m,vis[200005];
void dij(int u){
   priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
	q.push({0,u});
	while(!q.empty()){
		auto [dist, u] = q.top(); q.pop();
		if(dist > dis[u]) continue;
		if(!vis[u]){
			vis[u]=1;
			for(auto [v,w]:G[u]){
				if(dis[u]+a[v]+w < dis[v]){
					dis[v]=dis[u]+a[v]+w;
					q.push({dis[v],v});
				}
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
	dis[1]=a[1];
	dij(1);
for(int i=2;i<=n;i++){
	cout<<dis[i]<<' ';
}
	cout<<"\n";
	return 0;
}