#include <queue>
#include <vector>
#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pii;
const int N = 2e5 + 5;

int n, m;
ll a[N];
ll dis[N];
vector<pii> g[N];

void dijkstra() {
    priority_queue<pii, vector<pii>, greater<pii>> q;
    for (int i = 1; i <= n; ++i) {
        dis[i] = LLONG_MAX;
    }
    dis[1] = 0;
    q.push({0, 1});
    
    while (!q.empty()) {
        ll current_dist = q.top().first;
        int u = q.top().second;
        q.pop();
        
        if (current_dist > dis[u]) continue;
        
        for (auto edge : g[u]) {
            ll v = edge.second;
            ll cost = edge.first;
            if (dis[v] > dis[u] + cost) {
                dis[v] = dis[u] + cost;
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
        g[u].push_back({w + a[u] + a[v], v});
        g[v].push_back({w + a[u] + a[v], u});
    }
    dijkstra();
    for (int i = 2; i <= n; ++i) {
        printf("%lld ", dis[i]);
    }
    return 0;
}