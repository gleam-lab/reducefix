#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<climits> 
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pii;
const int N=2e5+5;
int n,m;
ll a[N];
ll dis[N];
bool vis[N];
vector<pii>g[N];

struct node
{
	ll dis,id;
	bool operator<(const node& x)const
	{
		return dis>x.dis;
	} 
};

void dijkstra()
{
	memset(vis,false,sizeof(vis));
	for(int i=1;i<=n;i++)
		dis[i]=LLONG_MAX;
	dis[1]=0;
	priority_queue<node>q;
	q.push({0,1});
	while(!q.empty())
	{
		node now=q.top();
		q.pop();
		if(vis[now.id])continue;
		vis[now.id]=true;
		for(pii i:g[now.id]) 
			if(dis[i.first]>dis[now.id]+i.second+a[i.first])
			{
				dis[i.first]=dis[now.id]+i.second+a[i.first];
				if(!vis[i.first])
					q.push({dis[i.first],i.first});
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