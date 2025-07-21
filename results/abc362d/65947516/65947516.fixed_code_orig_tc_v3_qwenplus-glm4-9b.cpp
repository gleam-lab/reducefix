#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 2e5 + 5;
int n, m;
ll a[N];
ll dis[N];
bool vis[N];
vector<pii> g[N];

void heap_dijkstra() {
    memset(vis, false, sizeof(vis));
    for (int i = 1; i <= n; i++) {
        dis[i] = LLONG_MAX;
    }
    dis[1] = 0;
    priority_queue<pii> q;
    q.push({1, 0});
    while (!q.empty()) {
        pii now = q.top();
        q.pop();
        int id = now.first;
        ll d = now.second;
        if (vis[id]) continue;
        vis[id] = true;
        for (pii i : g[id]) {
            if (dis[i.first] > d + i.second + a[id]) {
                dis[i.first] = d + i.second + a[id];
                q.push({i.first, dis[i.first]});
            }
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    heap_dijkstra();
    for (int i = 2; i <= n; i++)
        printf("%lld ", dis[i] + a[i]);
    return 0;
}