#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<ll, int> pli;

const int N = 2e5 + 5;
int n, m;
ll a[N];
ll dis[N];
bool vis[N];
vector<pli> g[N];

struct node {
    int id;
    ll dis;
    bool operator<(const node& x) const {
        return dis > x.dis;
    }
};

void heap_dijkstra() {
    memset(vis, false, sizeof(vis));
    for (int i = 1; i <= n; ++i)
        dis[i] = LLONG_MAX;
    dis[1] = 0;
    priority_queue<node> q;
    q.push({1, 0});
    
    while (!q.empty()) {
        node now = q.top();
        q.pop();
        
        if (vis[now.id]) continue;
        vis[now.id] = true;
        
        for (pli next : g[now.id]) {
            ll new_dis = dis[now.id] + next.second + a[next.first];
            if (new_dis < dis[next.first]) {
                dis[next.first] = new_dis;
                if (!vis[next.first])
                    q.push({next.first, new_dis});
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &a[i]);
    
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    
    heap_dijkstra();
    
    for (int i = 2; i <= n; ++i)
        printf("%lld%c", dis[i] + a[i], i == n ? '\n' : ' ');
    
    return 0;
}