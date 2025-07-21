#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<climits> 
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 2e5 + 5;
int n, m;
ll a[N], dist[N];
bool vis[N];
vector<pii> g[N];
struct node {
    int id, dis;
    bool operator<(const node& x) const {
        return dis > x.dis; // Use '>' for a max-heap
    }
};

void dijkstra() {
    memset(vis, false, sizeof(vis));
    for (int i = 1; i <= n; i++)
        dist[i] = LLONG_MAX;
    dist[1] = 0;
    priority_queue<node> pq;
    pq.push({1, 0});
    while (!pq.empty()) {
        node now = pq.top();
        pq.pop();
        if (vis[now.id]) continue;
        vis[now.id] = true;
        for (pii i : g[now.id]) {
            ll newDis = now.dis + i.second + a[now.id];
            if (dist[i.first] > newDis) {
                dist[i.first] = newDis;
                pq.push({i.first, dist[i.first]});
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
    dijkstra();
    for (int i = 2; i <= n; i++)
        printf("%lld ", dist[i] + a[i]);
    return 0;
}