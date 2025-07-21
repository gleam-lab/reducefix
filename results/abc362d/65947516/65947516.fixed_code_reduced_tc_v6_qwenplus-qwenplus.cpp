#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;  // Changed to use ll for distance

const int N = 2e5 + 5;

int n, m;
ll a[N];
ll dis[N];
bool vis[N];
vector<pli> g[N];  // Changed second value to ll since edge weights can be up to 1e9

struct node {
    int id;
    ll dist;
    bool operator<(const node& x) const {
        return dist > x.dist;
    }
};

void heap_dijkstra() {
    memset(vis, false, sizeof(vis));
    for (int i = 1; i <= n; i++)
        dis[i] = LLONG_MAX;  // Use LLONG_MAX for long long
    
    dis[1] = a[1];  // Start with vertex 1's value
    priority_queue<node> q;
    q.push({1, dis[1]});
    
    while (!q.empty()) {
        node now = q.top();
        q.pop();
        
        if (vis[now.id]) continue;
        vis[now.id] = true;
        
        for (pli edge : g[now.id]) {
            int next = edge.first;
            ll edge_weight = edge.second;
            
            // Calculate new path distance: current distance + edge weight + destination vertex weight
            ll new_dist = now.dist + edge_weight + a[next];
            
            if (!vis[next] && new_dist < dis[next]) {
                dis[next] = new_dist;
                q.push({next, dis[next]});
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
    
    return 0;
}