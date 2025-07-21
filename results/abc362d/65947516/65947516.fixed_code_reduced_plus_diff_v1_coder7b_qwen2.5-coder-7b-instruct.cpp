#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

const int N = 2e5 + 5;
int n, m;
ll a[N], dis[N];
bool vis[N];
vector<pii> g[N];

struct cmp {
    bool operator()(const pii &x, const pii &y) {
        return x.second > y.second;
    }
};

void dijkstra() {
    memset(vis, false, sizeof(vis));
    for (int i = 1; i <= n; i++) dis[i] = LLONG_MAX;
    dis[1] = 0;
    
    priority_queue<pii, vector<pii>, cmp> q;
    q.push({1, 0});

    while (!q.empty()) {
        pii now = q.top(); q.pop();
        if (vis[now.first]) continue;
        vis[now.first] = true;
        
        for (auto &[neighbor, weight] : g[now.first]) {
            if (dis[neighbor] > dis[now.first] + weight + a[now.first]) {
                dis[neighbor] = dis[now.first] + weight + a[now.first];
                if (!vis[neighbor]) q.push({neighbor, dis[neighbor]});
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);

    for (int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    dijkstra();

    for (int i = 2; i <= n; i++)
        printf("%lld ", dis[i] + a[i]);

    return 0;
}