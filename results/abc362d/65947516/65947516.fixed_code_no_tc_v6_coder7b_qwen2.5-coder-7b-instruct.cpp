#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<climits> 
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pli; // Changed to use long long for weights
const int N=2e5+5;
int n,m;
ll a[N];
ll dis[N];
bool vis[N];
vector<pair<ll,int>>g[N]; // Changed to use vector of pairs with long long weights
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
		dis[i]=LLONG_MAX; // Initialize distance to infinity
	dis[1]=0;
	priority_queue<node>q;
	q.push({1,0});
	while(!q.empty())
	{
		node now=q.top();
		q.pop();
		if(vis[now.id])continue;
		vis[now.id]=true;
		for(auto i:g[now.id]) 
			if(dis[i.second]>dis[now.id]+i.first+a[now.id]) // Corrected indexing and used first element for weight
			{
				dis[i.second]=dis[now.id]+i.first+a[now.id]; // Updated distance calculation
				if(!vis[i.second])
					q.push({i.second,dis[i.second]});
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
		ll w; // Added type definition for weight
		scanf("%d%d%lld",&u,&v,&w); // Corrected scanf format specifier for weight
		g[u].push_back({w,v}); // Pushed correct order of weight and vertex
		g[v].push_back({w,u});
	}
	heap_dijkstra();
	for(int i=2;i<=n;i++)
		printf("%lld ",dis[i]+a[i]); 
    return 0;
}