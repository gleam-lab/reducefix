#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<climits> 
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=2e5+5;
int n,m;
ll a[N];
ll dis[N];
bool vis[N];
vector<pii>g[N];
struct node
{
	int id;
	ll dis;
	node(int _id, ll _dis): id(_id), dis(_dis) {}
	bool operator>(const node& x)const
	{
		return dis>x.dis;
	} 
};
void dijkstra() {
	priority_queue<node, vector<node>, greater<node>> q;
	q.push(node(1, 0));
	dis[1] = 0;
	while (!q.empty()) {
		node now = q.top();
		q.pop();
		if (vis[now.id]) continue;
		vis[now.id] = true;
		for (auto& e : g[now.id]) {
			if (dis[e.first] > dis[now.id] + e.second + a[now.id]) {
				dis[e.first] = dis[now.id] + e.second + a[now.id];
				q.push(node(e.first, dis[e.first]));
			}
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		g[u].push_back(pii(v, w));
		g[v].push_back(pii(u, w));
	}
	dijkstra();
	for (int i = 2; i <= n; i++) printf("%lld ", dis[i] + a[i]);
	return 0;
}