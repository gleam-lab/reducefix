#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF LLONG_MAX

using namespace std;

typedef long long ll;
typedef pair<ll, int> pli;

const int MAXN = 2e5 + 5;

int n, m;
ll a[MAXN];
ll dis[MAXN];

vector<pli> g[MAXN];

void dijkstra() {
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [dist, u] = pq.top(); pq.pop();

        if (dist > dis[u]) continue;

        for (auto [v, w] : g[u]) {
            ll new_dist = dist + w + a[v];
            if (new_dist < dis[v]) {
                dis[v] = new_dist;
                pq.push({new_dist, v});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        dis[i] = INF;
    }

    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }

    dis[1] = 0;
    dijkstra();

    for (int i = 2; i <= n; ++i)
        cout << dis[i] + a[i] << ' ';

    return 0;
}