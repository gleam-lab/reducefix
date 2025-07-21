#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<climits> 
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;
const int N = 2e5 + 5;
int n, m;
ll a[N];
ll dis[N];
vector<pli> g[N];

void heap_dijkstra() {
    for(int i = 1; i <= n; i++)
        dis[i] = LLONG_MAX;
    dis[1] = a[1];
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    pq.push({dis[1], 1});
    while(!pq.empty()) {
        pli now = pq.top();
        pq.pop();
        ll d = now.first;
        int u = now.second;
        if(d > dis[u]) continue;
        for(pli edge : g[u]) {
            int v = edge.second;
            ll w = edge.first;
            if(dis[v] > d + w + a[v]) {
                dis[v] = d + w + a[v];
                pq.push({dis[v], v});
            }
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    for(int i = 1; i <= m; i++) {
        int u, v;
        ll w;
        scanf("%d%d%lld", &u, &v, &w);
        g[u].push_back({w, v});
        g[v].push_back({w, u});
    }
    heap_dijkstra();
    for(int i = 2; i <= n; i++)
        printf("%lld ", dis[i]);
    return 0;
}