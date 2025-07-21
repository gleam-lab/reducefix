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
    ll id, dis;
    bool operator<(const node& x) const {
        return dis > x.dis;
    }
};

void dijkstra() {
    memset(vis, false, sizeof(vis));
    for (int i = 1; i <= n; i++) {
        dis[i] = LLONG_MAX;
    }
    dis[1] = 0;
    priority_queue<node> q;
    q.push({0, 1});

    while (!q.empty()) {
        node now = q.top();
        q.pop();
        if (vis[now.id]) continue;
        vis[now.id] = true;
        for (pli i : g[now.id]) {
            if (dis[i.second] > dis[now.id] + i.first + a[i.second]) {
                dis[i.second] = dis[now.id] + i.first + a[i.second];
                if (!vis[i.second])
                    q.push({dis[i.second], i.second});
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        g[u].push_back({w, v});
        g[v].push_back({w, u});
    }
    dijkstra();
    for (int i = 2; i <= n; i++) {
        printf("%lld ", dis[i] + a[i]);
    }
    return 0;
}