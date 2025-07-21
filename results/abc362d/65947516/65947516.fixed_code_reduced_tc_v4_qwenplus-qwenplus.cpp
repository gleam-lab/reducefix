#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>
#include <limits.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pil; // {distance, node}

const int N = 2e5 + 5;

int n, m;
ll a[N];
ll dis[N];
bool vis[N];
vector<pil> g[N]; // {weight, node}

void dijkstra() {
    fill(dis, dis + n + 1, LLONG_MAX);
    memset(vis, 0, sizeof(vis));
    
    dis[1] = a[1]; // start includes vertex 1's weight
    priority_queue<pil, vector<pil>, greater<pil>> q;
    q.push({dis[1], 1});

    while (!q.empty()) {
        auto [d, u] = q.top();
        q.pop();
        if (vis[u]) continue;
        vis[u] = true;

        for (auto &[v, b] : g[u]) {
            if (!vis[v] && dis[v] > dis[u] + b + a[v] - a[u]) {
                // Explanation: 
                // - dis[u] includes a[u]
                // - Adding edge b
                // - Add a[v] (next vertex)
                // So subtract a[u] to avoid double-counting
                dis[v] = dis[u] + b + a[v] - a[u];
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

    for (int i = 0; i < m; ++i) {
        int u, v;
        ll b;
        scanf("%d%d%lld", &u, &v, &b);
        g[u].push_back({b, v});
        g[v].push_back({b, u});
    }

    dijkstra();

    for (int i = 2; i <= n; ++i) {
        printf("%lld ", dis[i]);
    }

    return 0;
}