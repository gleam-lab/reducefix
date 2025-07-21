#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pli; // Changed to use long long for distances
const int N = 2e5 + 5;

int n, m;
ll a[N];
ll dis[N];
bool vis[N];
vector<pli> g[N]; // Changed to store edge weights as ll

void dijkstra() {
    memset(vis, false, sizeof(vis));
    for (int i = 1; i <= n; i++)
        dis[i] = LLONG_MAX; // Use LLONG_MAX for long long
    dis[1] = a[1]; // Include A_1 since we start at vertex 1
    
    priority_queue<pli, vector<pli>, greater<pli>> q;
    q.push({dis[1], 1});
    
    while (!q.empty()) {
        auto [d, u] = q.top();
        q.pop();
        
        if (vis[u]) continue;
        vis[u] = true;
        
        for (auto [v, b] : g[u]) {
            // Calculate total path cost to v through u:
            // current path cost to u + edge weight + vertex weight of v
            if (!vis[v] && dis[v] > dis[u] + b + a[v]) {
                dis[v] = dis[u] + b + a[v];
                q.push({dis[v], v});
            }
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    
    for (int i = 1; i <= m; i++) {
        int u, v;
        ll w;
        scanf("%d%d%lld", &u, &v, &w);
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    
    dijkstra();
    
    for (int i = 2; i <= n; i++)
        printf("%lld ", dis[i]);
    
    return 0;
}