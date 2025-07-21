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

struct cmp {
    bool operator() (const pll &a, const pll &b) const {
        return a.second > b.second;
    }
};

void dijkstra() {
    memset(vis, false, sizeof(vis));
    for(int i = 1; i <= n; i++) dis[i] = LONG_LONG_MAX;
    dis[1] = 0;
    priority_queue<pll, vector<pll>, cmp> pq;
    pq.push({1, 0});

    while(!pq.empty()) {
        auto [now, dist] = pq.top(); pq.pop();
        if(vis[now]) continue;
        vis[now] = true;

        for(auto [next, cost] : g[now]) {
            ll new_cost = dist + cost + a[next];
            if(new_cost < dis[next]) {
                dis[next] = new_cost;
                pq.push({next, new_cost});
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);

    for(int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    dijkstra();

    for(int i = 2; i <= n; i++)
        printf("%lld ", dis[i] + a[i]);

    return 0;
}