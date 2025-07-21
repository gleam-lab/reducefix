#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<climits> 
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const int N=2e5+5;
int n,m;
ll a[N];
ll dis[N];
bool vis[N];
vector<pll>g[N];
struct node
{
	ll id,dis;
	bool operator<(const node& x)const
	{
		return dis>x.dis;
	} 
};
void heap_dijkstra()
{
	memset(vis,false,sizeof(vis));
	for(int i=1;i<=n;i++)
		dis[i]=LONG_LONG_MAX;
	dis[1]=0;
	priority_queue<node>q;
	q.push({1,0});
	while(!q.empty())
	{
		node now=q.top();
		q.pop();
		if(vis[now.id])continue;
		vis[now.id]=true;
		for(pll i:g[now.id]) 
			if(dis[i.first]>dis[now.id]+i.second+a[now.id])
			{
				dis[i.first]=dis[now.id]+i.second+a[now.id];
				if(!vis[i.first])
					q.push({i.first,dis[i.first]});
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
		int u,v;
		ll w;
		scanf("%d%d%lld",&u,&v,&w);
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	heap_dijkstra();
	for(int i=2;i<=n;i++)
		printf("%lld ",dis[i]+a[i]); 
    return 0;
}