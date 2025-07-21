#include<bits/stdc++.h>
using namespace std;
#define int long long 
vector<pair<int,int>>G[200005];
int dis[200005],a[200005],n,m;
void dij(){
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>q;
	q.push({a[1],1});
	while(!q.empty()){
		int u=q.top().second,d=q.top().first;
		q.pop();
		if(d>dis[u]) continue; // Skip outdated distances
		for(auto [v,w]:G[u]){
			int nd=d+a[v]+w;
			if(nd<dis[v]){
				dis[v]=nd;
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
	memset(dis,0x3f,sizeof dis);
	dis[1]=a[1];
	dij();
for(int i=2;i<=n;i++){
	cout<<dis[i]<<' ';
}
	cout<<"\n";
	return 0;
}