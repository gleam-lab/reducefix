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
bool vis[N];
vector<pli> g[N];

void dijkstra() {
    memset(vis, false, sizeof(vis));
    fill(dis, dis + n + 1, LLONG_MAX);
    dis[1] = 0;
    
    priority_queue<pli, vector<pli>, greater<pli>> q;
    q.push({0, 1});

    while (!q.empty()) {
        auto [dist, u] = q.top(); q.pop();
        
        if (vis[u]) continue;
        vis[u] = true;

        for (auto &[v, w] : g[u]) {
            if (dis[v] > dist + w + a[v]) {
                dis[v] = dist + w + a[v];
                q.push({dis[v], v});
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]);

    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }

    dijkstra();

    for (int i = 2; i <= n; ++i)
        printf("%lld ", dis[i]);

    return 0;
}