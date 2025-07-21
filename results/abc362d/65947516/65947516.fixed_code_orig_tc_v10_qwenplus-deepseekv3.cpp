#include <queue>
#include <vector>
#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;
const int N = 2e5 + 5;
const ll INF = LLONG_MAX;

int n, m;
ll a[N];
ll dis[N];
vector<pair<int, ll>> g[N];

void heap_dijkstra() {
    for (int i = 1; i <= n; ++i) {
        dis[i] = INF;
    }
    dis[1] = a[1];
    priority_queue<pli, vector<pli>, greater<pli>> q;
    q.push({dis[1], 1});
    while (!q.empty()) {
        ll d = q.top().first;
        int u = q.top().second;
        q.pop();
        if (d > dis[u]) continue;
        for (auto &edge : g[u]) {
            int v = edge.first;
            ll w = edge.second;
            if (dis[v] > dis[u] + w + a[v]) {
                dis[v] = dis[u] + w + a[v];
                q.push({dis[v], v});
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
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    heap_dijkstra();
    for (int i = 2; i <= n; ++i) {
        printf("%lld ", dis[i]);
    }
    return 0;
}