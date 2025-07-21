#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<climits> 
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;
const int N=2e5+5;
int n,m;
ll a[N];
ll dis[N];
bool vis[N];
vector<pli> g[N];

void heap_dijkstra() {
    memset(vis, false, sizeof(vis));
    for(int i=1; i<=n; i++)
        dis[i] = LONG_LONG_MAX;
    dis[1] = a[1]; // The path starts at vertex 1, so include its weight
    priority_queue<pli, vector<pli>, greater<pli>> q;
    q.push({dis[1], 1});
    while(!q.empty()) {
        pli now = q.top();
        q.pop();
        int u = now.second;
        if(vis[u]) continue;
        vis[u] = true;
        for(pli edge : g[u]) {
            int v = edge.second;
            ll w = edge.first;
            if(dis[v] > dis[u] + w + a[v]) {
                dis[v] = dis[u] + w + a[v];
                q.push({dis[v], v});
            }
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; i++)
        scanf("%lld", &a[i]);
    for(int i=1; i<=m; i++) {
        int u, v;
        ll w;
        scanf("%d%d%lld", &u, &v, &w);
        g[u].push_back({w, v});
        g[v].push_back({w, u});
    }
    heap_dijkstra();
    for(int i=2; i<=n; i++)
        printf("%lld ", dis[i]);
    return 0;
}