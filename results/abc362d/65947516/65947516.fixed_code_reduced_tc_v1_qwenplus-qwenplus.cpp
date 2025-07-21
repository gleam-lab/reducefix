#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>
#include <limits>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 2e5 + 5;
int n, m;
ll a[N];
ll dis[N];
bool vis[N];
vector<pii> g[N];

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
        dis[i] = numeric_limits<ll>::max();
    
    dis[1] = a[1]; // Start includes vertex 1's weight
    priority_queue<node> q;
    q.push({1, dis[1]});
    
    while (!q.empty()) {
        node now = q.top();
        q.pop();
        if (vis[now.id]) continue;
        vis[now.id] = true;
        
        for (pii edge : g[now.id]) {
            int neighbor = edge.first;
            ll edge_weight = edge.second;
            ll new_dist = now.dist + edge_weight + a[neighbor];
            
            if (!vis[neighbor] && dis[neighbor] > new_dist) {
                dis[neighbor] = new_dist;
                q.push({neighbor, dis[neighbor]});
            }
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    
    heap_dijkstra();
    
    for (int i = 2; i <= n; i++)
        printf("%lld ", dis[i]);
    
    return 0;
}