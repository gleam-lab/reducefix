#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;  // Changed to use long long for distances

const int N = 2e5 + 5;

int n, m;
ll a[N];
ll dis[N];
bool vis[N];
vector<pli> g[N];  // Edge weight can be up to 1e9, so use long long

void heap_dijkstra() {
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++)
        dis[i] = LLONG_MAX;  // Use LLONG_MAX for initializing long long values
    
    dis[1] = a[1];  // Start with vertex 1's weight
    priority_queue<pli, vector<pli>, greater<pli>> q;  // Min-heap based on distance
    q.push({dis[1], 1});
    
    while (!q.empty()) {
        ll d = q.top().first;
        int u = q.top().second;
        q.pop();
        
        if (vis[u]) continue;
        vis[u] = true;
        
        for (auto &edge : g[u]) {
            int v = edge.first;
            ll b = edge.second;
            
            // Calculate new distance: current path cost + edge weight + destination vertex weight
            ll new_dist = d + b + a[v];
            
            if (new_dist < dis[v]) {
                dis[v] = new_dist;
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
    
    heap_dijkstra();
    
    for (int i = 2; i <= n; i++) {
        printf("%lld ", dis[i]);
    }
    printf("\n");
    
    return 0;
}