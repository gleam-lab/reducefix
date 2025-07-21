#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<ll, int> pli;

const int MAXN = 2e5 + 5;

int n, m;
ll a[MAXN];
vector<pli> g[MAXN];

void dijkstra() {
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    vector<ll> dist(n + 1, LLONG_MAX);
    
    dist[1] = 0;
    pq.emplace(0, 1);

    while (!pq.empty()) {
        auto [cost, u] = pq.top(); pq.pop();

        if (cost > dist[u]) continue;

        for (auto &[v, w] : g[u]) {
            ll new_cost = cost + w + a[v];
            if (new_cost < dist[v]) {
                dist[v] = new_cost;
                pq.emplace(new_cost, v);
            }
        }
    }

    for (int i = 2; i <= n; ++i) {
        cout << dist[i] << " ";
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    dijkstra();
    return 0;
}