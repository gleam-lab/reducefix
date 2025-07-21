#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<climits> 
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll,pair<int,int>> plii;
const int N=2e5+5;
int n,m;
ll a[N];
ll dis[N];
bool vis[N];
vector<pair<int,ll>> g[N];

void dijkstra()
{
	memset(vis,false,sizeof(vis));
	for(int i=1;i<=n;i++)
		dis[i]=LLONG_MAX;
	dis[1]=0;
	priority_queue<plii,vector<plii>,greater<plii>> q;
	q.push({0,{1,0}});
	while(!q.empty())
	{
		plii now=q.top();
		q.pop();
		int u=now.second.first;
		ll d=now.second.second;
		if(vis[u]) continue;
		vis[u]=true;
		for(auto &i:g[u]) 
		{
			int v=i.first;
			ll w=i.second;
			if(dis[v]>d+w+a[u])
			{
				dis[v]=d+w+a[u];
				q.push({dis[v],{v,d+w+a[u]}});
			}
		}
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	dijkstra();
	for(int i=2;i<=n;i++)
		printf("%lld ",dis[i]); 
    return 0;
}