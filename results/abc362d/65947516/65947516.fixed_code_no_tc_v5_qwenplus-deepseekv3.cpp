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

void dijkstra() {
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    for (int i = 1; i <= n; i++) {
        dis[i] = LONG_LONG_MAX;
    }
    dis[1] = a[1];
    pq.push({dis[1], 1});
    
    while (!pq.empty()) {
        ll current_dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        if (current_dist > dis[u]) continue;
        
        for (auto edge : g[u]) {
            int v = edge.second;
            ll cost = edge.first;
            if (dis[v] > dis[u] + cost + a[v]) {
                dis[v] = dis[u] + cost + a[v];
                pq.push({dis[v], v});
            }
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        ll w;
        scanf("%d%d%lld", &u, &v, &w);
        g[u].push_back({w, v});
        g[v].push_back({w, u});
    }
    dijkstra();
    for (int i = 2; i <= n; i++) {
        printf("%lld ", dis[i]);
    }
    return 0;
}