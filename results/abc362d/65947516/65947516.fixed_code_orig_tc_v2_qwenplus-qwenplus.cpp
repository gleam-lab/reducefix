#include <queue>
#include <vector>
#include <cstdio>
#include <climits>
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

struct node {
    int id;
    ll dist;
    bool operator<(const node& x) const {
        return dist > x.dist;
    }
};

void heap_dijkstra() {
    priority_queue<node> q;
    fill(dis, dis + n + 1, LLONG_MAX);
    memset(vis, false, sizeof(vis));
    
    dis[1] = a[1]; // Include A_1 at the start
    q.push({1, dis[1]});
    
    while (!q.empty()) {
        node now = q.top();
        q.pop();
        if (vis[now.id]) continue;
        vis[now.id] = true;
        
        for (auto e : g[now.id]) {
            int v = e.first;
            ll edge_weight = e.second;
            ll new_dist = dis[now.id] + edge_weight + a[v]; // Add A_v when entering node v
            
            if (!vis[v] && new_dist < dis[v]) {
                dis[v] = new_dist;
                q.push({v, dis[v]});
            }
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &a[i]);
    
    for (int i = 1; i <= m; ++i) {
        int u, v;
        ll w;
        scanf("%d%d%lld", &u, &v, &w);
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    heap_dijkstra();

    for (int i = 2; i <= n; ++i)
        printf("%lld ", dis[i]);

    return 0;
}