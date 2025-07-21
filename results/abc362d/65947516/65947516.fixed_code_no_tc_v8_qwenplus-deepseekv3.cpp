#include <queue>
#include <vector>
#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;
const int N = 2e5 + 5;
const ll INF = LONG_LONG_MAX;

int n, m;
ll a[N];
ll dis[N];
vector<pli> g[N];

void dijkstra() {
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    for (int i = 1; i <= n; ++i) {
        dis[i] = INF;
    }
    dis[1] = a[1];
    pq.push({dis[1], 1});
    
    while (!pq.empty()) {
        ll d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        if (d > dis[u]) continue;
        
        for (pli edge : g[u]) {
            ll w = edge.first;
            int v = edge.second;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                pq.push({dis[v], v});
            }
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
    }
    for (int i = 1; i <= m; ++i) {
        int u, v;
        ll w;
        scanf("%d%d%lld", &u, &v, &w);
        g[u].push_back({w + a[v], v});
        g[v].push_back({w + a[u], u});
    }
    
    dijkstra();
    
    for (int i = 2; i <= n; ++i) {
        printf("%lld ", dis[i]);
    }
    return 0;
}